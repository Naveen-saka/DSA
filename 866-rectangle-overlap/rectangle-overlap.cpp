class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // rec = {x1, y1, x2, y2}
        double cx1 = (rec1[0] + rec1[2]) / 2.0;
        double cy1 = (rec1[1] + rec1[3]) / 2.0;
        double cx2 = (rec2[0] + rec2[2]) / 2.0;
        double cy2 = (rec2[1] + rec2[3]) / 2.0;

        double w1 = rec1[2] - rec1[0];
        double h1 = rec1[3] - rec1[1];
        double w2 = rec2[2] - rec2[0];
        double h2 = rec2[3] - rec2[1];

        return fabs(cx1 - cx2) < (w1/2.0 + w2/2.0) &&
               fabs(cy1 - cy2) < (h1/2.0 + h2/2.0);
    }
};
