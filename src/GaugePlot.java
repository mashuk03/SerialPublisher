import meter.*;
import processing.core.PApplet;
public class GaugePlot {
    private Meter m_;
    private double alpha_ = 0.25;
    private double value_ = 0;

    public  GaugePlot(int [] pos, PApplet applet)
    {
        // default location x,y: (25, 25)
        m_ = new Meter(applet, pos[0], pos[1]); // Instantiate a meter class.
        m_.setDisplayDigitalMeterValue(true);
    }
    public void update(int value)
    {
        value_ = alpha_*value_ + (1-alpha_)*value;
        m_.updateMeter((int)value_);
    }
}
