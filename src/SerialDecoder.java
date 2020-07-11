import com.fazecast.jSerialComm.*;
import java.io.InputStream;
import java.util.Scanner;

public class SerialDecoder {
    private int BAUD_RATE = 2000000;
    private String data_ = "";
    private Boolean isDataAvailable_ = false;
    private Boolean isWriteAvailable_ = false;
    SerialPort comPort;

    public SerialDecoder(int port)
    {
        comPort = SerialPort.getCommPorts()[port];
        comPort.openPort();
        comPort.setBaudRate(BAUD_RATE);
        MessageListener listener = new MessageListener();
        comPort.addDataListener(listener);
    }

    public Boolean update()
    {
        Boolean result = isDataAvailable_;
        isDataAvailable_ = false;
        return result;
    }
    public String getData()
    {
        return data_;
    }
    public void sendData(int value)
    {
        String command = String.valueOf(value)+"\n";
        if(isWriteAvailable_)
        comPort.writeBytes(command.getBytes(), command.length());


    }

    private final class MessageListener implements SerialPortMessageListener
    {
        @Override
        public int getListeningEvents() { return SerialPort.LISTENING_EVENT_DATA_RECEIVED; }

        @Override
        public byte[] getMessageDelimiter() { return new byte[] { (byte)'\n' }; }

        @Override
        public boolean delimiterIndicatesEndOfMessage() { return true; }

        @Override
        public void serialEvent(SerialPortEvent event)
        {
            byte[] newData = event.getReceivedData();
            data_ = "";
            for (int i = 0; i < newData.length; ++i)
                data_ += (char)newData[i];
//                System.out.print((char)newData[i]);
            data_ = data_.trim();
            data_ = data_.replaceAll("\n","");
            isDataAvailable_ = true;
            isWriteAvailable_ = true;
        }
    }


}
