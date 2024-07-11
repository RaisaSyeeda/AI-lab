#include<bits/stdc++.h>
using namespace std;

int grid[10][10] = {//10x10 grid
    {0,0,0,1,0,0,0,0,0,1},
    {0,1,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0},
    {0,0,1,0,0,0,0,0,1,0},
};

int x[10] = {-1,0,0,1};
int y[10] = {0,1,-1,0};//g up, right, left, and down


int vis[10][10];//this 2D array named vis is used to mark visited cells in the grid during the DFS traversal
int coun = 0;//counter variable that keeps track of how many cells marked as '1' have been visited.

int dfs(int i, int j, int cost){//The dfs function is the core of the DFS traversal on the grid.
    //It takes the current position (i, j) and the current cost as arguments.

    vis[i][j] = 1;//The function starts by marking the current cell as visited

    if(grid[i][j]==1) coun++;//If the current cell contains a '1' (an obstacle), coun is incremented.

    if(coun==11) return cost;//If coun reaches 11 (all 11 '1's are visited), the function returns the current cost.

    int cost1 = 0;
    for( int l = 0;l < 4; l++){//The function then iterates over the possible movement directions (up, right, left, down).
        int new1 = i + x[l];//or each direction, it calculates the new position (new1, new2) based on (i, j) and the movement arrays x and y
        int new2 = j + y[l];

        if(coun == 11 || new1 <0 || new2<0 || new1>9 || new2>9 || vis[new1][new2]==1) continue;
        //If the new position is out of bounds or has already been visited, the loop continues to the next direction.

        cost1 = dfs(new1,new2, cost) + 1;//Otherwise, it recursively calls the dfs function with the new position and an incremented cost.
        //The result is assigned to cost1.
    }
    return cost1;
}
int main(){
    cout << "Cost: "<< dfs(9,0,0) <<endl;

    for( int i = 0; i < 10; i++){
        for( int j = 0; j < 10; j++){
            //cout << vis[i][j]<<" "; //vissited cells
        }
        cout <<endl;
    }
}
/*The main function initiates the DFS traversal by calling dfs(9,0,0) with the starting position (9, 0) and an initial cost of 0.
After the traversal is complete, the shortest path's cost is printed.
It then prints the vis array, indicating the visited cells during the DFS traversal.

//This code appears to find the shortest path through the grid of obstacles using a DFS approach.
It marks visited cells and increments a cost until all '1' cells are visited, and then it returns the cost of the shortest path*/
/*
...D.....D
.D...D....
..........
....D...D.
..........
.D........
.......D..
..........
......D...
V.D.....D.
*/
