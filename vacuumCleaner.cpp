#include<bits/stdc++.h>
using namespace std;

char vacc[20][20];
int vstd[20][20];

int n = 10, dirt = 0, res = 1e9;
int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1};


void bfs(int i, int j, int cost, int drt){
	if(drt == 0) {
		res = cost;
		return;
	}
	vstd[i][j] = 1;

	for( int l = 0; l < 4; l++){
		int nX = i + dx[l];
		int nY = j + dy[l];

		if(nX >=1 && nX<= 10 && nY <= 10 && nY>=1 && vstd[nX][nY] == 0){
			if(vacc[nX][nY] == 'D') drt--;
			bfs(pos);
			bfs(nX, nY, cost+1, drt);
		}
	}
}

int main() {
    int posX, posY;
    for( int i = 1;i <= n; i++){
    	for( int j = 1;j <= n; j++){
    		cin >> vacc[i][j];
    		if(vacc[i][j] == 'D') dirt++;
    		if(vacc[i][j] == 'V') {
    			posX = i;
    			posY = j;
    		}
    	}
    }
    dfs(posX, posY, 0, dirt);
    cout<< endl;
    cout <<"Cost in DFS: " << res<<endl;
    cout << "Cost in BFS: " << res2 <<endl;
}
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
