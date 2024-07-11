#include<bits/stdc++.h>
using namespace std;
#define ln "\n"

void printboard(vector<int> board){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(board[j]==i+1) cout<<'Q'<<" ";
            else cout<<"_"<<" ";
        }
        cout<<ln;
    }
}

int huristic(vector<int> board){
    int hur=0;
    for(int i=0; i<8; i++){
        for(int j=i+1; j<8; j++){
            if(board[i]==board[j] || abs(board[i]-board[j])==j-i){
                hur++;
            }
        }
    }
    return hur*2;
}

vector<int> bestneighbour(vector<int> board){
    int min_huristic = huristic(board);
    vector<int> current_state = board;
    vector<int> final = board;
    for(int i=0; i<8; i++){
        for(int j=1; j<=8; j++){
            if(board[i]!=j){
                vector<int> new_temp_state = board;
                new_temp_state[i]=j;
                int current_huristic = huristic(new_temp_state);
                if(current_huristic<min_huristic){
                    min_huristic = current_huristic;
                    current_state = new_temp_state;
                    final[i] = j;
                }
            }
        }
    }
    return final;
}

int main(){

    vector<int> initial={4,3,6,2,5,4,7,3};

     /*for (int i = 0; i < 8; i++){
        cin >> initial[i];
        initial.push_back(i);
     }
    */
    // cout<<"hurist val = "<<huristic(initial)<<"\n";
    // printboard(initial);

    vector<int> board = initial;
    int currhuri = huristic(board);
    while(1){
        vector<int> poss = bestneighbour(board);
        int nexthuri=huristic(poss);
        if(nexthuri>=currhuri){
            board = poss; break;
        }
        cout<<"For the current huristic = "<< currhuri<<ln;
        printboard(board);
        cout<<endl;
        board = poss;
        currhuri = nexthuri;
    }
    cout<<"Latest huristic = "<<currhuri<<ln;
    printboard(board);
    cout<<endl;

}

