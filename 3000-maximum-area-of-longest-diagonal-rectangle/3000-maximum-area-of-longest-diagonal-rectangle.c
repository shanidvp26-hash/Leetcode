int areaOfMaxDiagonal(int** dimensions, int dimensionsSize, int* dimensionsColSize){
    double maxDiag = -1.0;
    int maxArea = 0;

    for(int i = 0; i < dimensionsSize; i++){
        int l = dimensions[i][0];
        int w = dimensions[i][1];

        double diag = sqrt((double)l * l + (double)w * w);
        int area = l * w;

        if(diag > maxDiag){
            maxDiag = diag;
            maxArea = area;
        } 
        else if(fabs(diag - maxDiag) < 1e-9){ 
            // diagonals equal → choose max area
            if(area > maxArea){
                maxArea = area;
            }
        }
    }

    return maxArea;
}