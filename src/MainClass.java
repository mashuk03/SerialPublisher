import processing.core.PApplet;
import controlP5.*;
import java.util.*;

public class MainClass extends PApplet {

    SerialDecoder serialDecoder;
    private int COM_INDEX = 2;

    ArrayList<SensorData> sensorData;
    ArrayList<GaugePlot> gaugePlots;
    LinePlot linePlot1, linePlot2;
    ControlP5 jControl, kControl;
    public static PApplet processing;

    public void setup()
    {

        processing = this;
        serialDecoder = new SerialDecoder(COM_INDEX);
        // sensorData = <ALL THE INFO THAT NEED TO BE VISUALIZED>
        sensorData = new ArrayList<SensorData>();
        sensorData.add(new SensorData("/STEER_SENSOR_ONE_PIN"));
        sensorData.add(new SensorData("/STEER_SENSOR_TWO_PIN"));
        sensorData.add(new SensorData("/SINEWAVE"));
        sensorData.add(new SensorData("/COSWAVE"));

        gaugePlots = new ArrayList<GaugePlot>();
        int m1[] = {25, 25};
        int m2[] = {550, 25};
        gaugePlots.add(new GaugePlot(m1, this));
        gaugePlots.add(new GaugePlot(m2, this));

        int rgb[] ={127,34,255};
        linePlot1 = new LinePlot(rgb, this);
        rgb[0] = 255;
        linePlot2 = new LinePlot(rgb, this);
        background(0);

        jControl = new ControlP5(this);
        jControl.addSlider("Amplitude", 0, 99, 0, 10, 5, 255, 20);
        kControl = new ControlP5(this);
        kControl.addSlider("Period", 256, 513, 100, 400, 5, 255, 20);
    }
    public void settings() {
        size(1000, 600);

    }

    public void draw()
    {
        if(serialDecoder.update())
        {
            String data = serialDecoder.getData();
            // It is important to have the data printed.
            // Stream buffer waiting on the serial port need to be efficiently delivered.
            println(data);
            for (int i =0; i< sensorData.size(); ++i)
            {
                sensorData.get(i).decode(data);
                if(sensorData.get(i).isUpdated())
                {
                    float value = sensorData.get(i).getVALUE();
                    // Add plot (case) based on the SENSOR_TYPE
                    switch (i)
                    {
                        case 2:
                        {
                            float line_value = map(value, 0, 255, 0, height-300);
                            linePlot1.update(line_value);break;
                        }
                        case 3:
                        {
                            float line_value = map(value, 0, 513, 0, height-300);
                            linePlot2.update(line_value);break;
                        }
                        default:
                        {
                            value = map(value, 0, 1023, 0, 255);
                            gaugePlots.get(i).update((int)value);break;
                        }
                    }
                }
            }

        }

    }

    public void Amplitude(float theColor)
    {
        serialDecoder.sendData((int)theColor);
//        println(" Amplitude");
    }
    public void Period(float theColor)
    {
        serialDecoder.sendData((int)theColor);
//        println(" period");
    }


    public static void main(String[] args)
    {
        println("Executing Arduino Processing Interface");
        PApplet.main("MainClass",args);
    }
}
