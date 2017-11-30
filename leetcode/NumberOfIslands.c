int numIslands(char** grid, int gridRowSize, int gridColSize) {
    if(gridRowSize == 0 || gridColSize == 0) return 0;
    int res = 0;
    bool** visited;
#    visited = (bool**)malloc(gridRowSize*gridColSize*sizeof(bool*));
    
    visited = malloc(gridRowSize * sizeof(bool*)); // Allocate row pointers
    for(int i = 0; i < gridRowSize; i++)
        visited[i] = malloc(gridColSize * sizeof(bool));
    
    for(int i =0;i<gridRowSize;i++)
        for(int j =0; j<gridColSize;j++)
            visited[i][j] = false;
    
    for(int i = 0;i<gridRowSize;i++){
        for(int j = 0; j < gridRowSize;j++){
            if(grid[i][j] == '1' && !visited[i][j]){
                numIslandsDFS(grid,gridRowSize,gridColSize,visited,i,j);
                ++res;
            }
        }
    }
    return res;
}

void numIslandsDFS(char** grid, int gridRowSize, int gridColSize, bool** visited, int x, int y){
    if(x<0 || x>=gridRowSize) return;
    if(y<0 || y>=gridColSize) return;
    if(grid[x][y] != '1' || visited[x][y]) return;
    
    visited[x][y] = true;
    
    numIslandsDFS(grid,gridRowSize,gridColSize,visited,x-1,y);
    numIslandsDFS(grid,gridRowSize,gridColSize,visited,x+1,y);
    numIslandsDFS(grid,gridRowSize,gridColSize,visited,x,y-1);
    numIslandsDFS(grid,gridRowSize,gridColSize,visited,x,y+1);
}