class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nx = xCenter , ny = yCenter;
        if(x1 > xCenter) nx = x1;
        else if(x2 < xCenter) nx = x2;
        
        if(y1 > yCenter) ny = y1;
        else if(y2 < yCenter) ny = y2;

        int d = abs(nx-xCenter)*abs(nx-xCenter) + abs(ny-yCenter)*abs(ny-yCenter);
        
        return d<=radius*radius;
    }
};