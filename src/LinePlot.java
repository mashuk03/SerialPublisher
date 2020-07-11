import processing.core.PApplet;

public class LinePlot
{
    private int xPos = 1;         // horizontal position of the graph
    //Variables to draw a continuous line.
    private int lastxPos=1;
    private int lastheight=0;
    private PApplet _this;
    private int[] rgb;


    public LinePlot(int[] color, PApplet applet)
    {
        _this = applet;
        rgb = color.clone();
        _this.strokeWeight(4);        //stroke wider
    }

    public void update(float inByte)
    {
        m_plot(inByte);
    }

    private void m_plot(float inByte)
    {
        _this.stroke(rgb[0],rgb[1],rgb[2]);     //stroke color
        _this.line(lastxPos, lastheight, xPos, _this.height - inByte);
        lastxPos= xPos;
        lastheight= (int) (_this.height-inByte);

        // at the edge of the window, go back to the beginning:
        if (xPos >= _this.width) {
            xPos = 0;
            lastxPos= 0;
            _this.background(0);  //Clear the screen.
        }
        else {
            // increment the horizontal position:
            xPos++;
        }
    }
}