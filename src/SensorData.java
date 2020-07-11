import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class SensorData {
    private String topic_;
    public float VALUE;
    private Boolean isUpdated_ = false;

    public  SensorData(String topic)
    {
        this.topic_ = topic;
    }
    public float getVALUE()
    {
        isUpdated_ = false;
        return VALUE;
    }
    private Boolean m_match(String data, String template)
    {
        Boolean result = false;
        Matcher m = Pattern.compile(template)
                .matcher(data);
        while (m.find()) {
            result = true;
        }
        return result;
    }
    public Boolean isUpdated()
    {
        return isUpdated_;
    }

    public void decode(String data)
    {
        String[] parts = data.split("\t");
        if(m_match(parts[0], topic_)) // if the data belong to this topic
        {
            try {
                VALUE = Float.parseFloat(parts[1]);
                isUpdated_ = true;
            }
            catch(Exception e) {
                VALUE = 0;
                isUpdated_ = false;
            }
        }
    }

}
