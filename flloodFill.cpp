// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
// You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].
// To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color 
// as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.
// Return the modified image after performing the flood fill.

//using DFS

    void dfs(vector<vector<int>> & image,int sr,int sc,int icol, int col){
    
        if(image[sr][sc] != icol or image[sr][sc] == col) return ;

        image[sr][sc] = col;

        if(sr>0){
            dfs(image,sr-1,sc,icol,col);
        }
        if(sc>0){
            dfs(image,sr,sc-1,icol,col);
        }
        if(sr<image.size()-1){
            dfs(image,sr+1,sc,icol,col);
        }
        if(sc<image[0].size()-1){
            dfs(image,sr,sc+1,icol,col);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }