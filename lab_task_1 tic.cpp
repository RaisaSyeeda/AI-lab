#include<bits/stdc++.h>
using namespace std;

int currentTurn = 1;
int player = 1;
int ai = -1;
int mainBoard[9] = {0,0,0,0,0,0,0,0,0};

char convert(int a){
    if (a == -1){
        return 'O';
    }
    else if (a == 1){
        return 'X';
    }
    else return '-';
}

void print_board(int mainBoard[10]){
    /*for( int j = 0; j < 4; j++){
        cout <<"- ";
    }
    */
    cout <<endl;
    cout << convert(mainBoard[0]) <<" "<< convert(mainBoard[1])<<" "<<convert(mainBoard[2])<<endl;
    cout << convert(mainBoard[3]) <<" "<< convert(mainBoard[4])<<" "<<convert(mainBoard[5])<<endl;
    cout << convert(mainBoard[6]) <<" "<< convert(mainBoard[7])<<" "<<convert(mainBoard[8])<<endl;
    cout <<endl;
    /*for( int j = 0; j < 4; j++){
        cout <<"- ";
    }
    cout <<endl;
    */
}

int checkWinCondition(int SG[9]) {
    int a = 1;
    if (SG[0] + SG[1] + SG[2] == a * 3 ||
        SG[3] + SG[4] + SG[5] == a * 3 ||
        SG[6] + SG[7] + SG[8] == a * 3 ||
        SG[0] + SG[3] + SG[6] == a * 3 ||
        SG[1] + SG[4] + SG[7] == a * 3 ||
        SG[2] + SG[5] + SG[8] == a * 3 ||
        SG[0] + SG[4] + SG[8] == a * 3 ||
        SG[2] + SG[4] + SG[6] == a * 3){
        return a;
    }
    a = -1;
    if (SG[0] + SG[1] + SG[2] == a * 3 ||
        SG[3] + SG[4] + SG[5] == a * 3 ||
        SG[6] + SG[7] + SG[8] == a * 3 ||
        SG[0] + SG[3] + SG[6] == a * 3 ||
        SG[1] + SG[4] + SG[7] == a * 3 ||
        SG[2] + SG[5] + SG[8] == a * 3 ||
        SG[0] + SG[4] + SG[8] == a * 3 ||
        SG[2] + SG[4] + SG[6] == a * 3){
        return a;
    }
    return 0;
}

int evaluatePos(int pos[10], int square){
    pos[square] = ai;
    int evaluation = 0;
    //Prefer center over corners over edges
    //evaluation -= (pos[0]*0.2+pos[1]*0.1+pos[2]*0.2+pos[3]*0.1+pos[4]*0.25+pos[5]*0.1+pos[6]*0.2+pos[7]*0.1+pos[8]*0.2);
    int points[10] = {2, 4, 2, 4, 8, 4, 2, 4, 2};

    int a = 2;
    evaluation+=points[square];

    //Prefer creating pairs
    a = -2;
    if(pos[0] + pos[1] + pos[2] == a || pos[3] + pos[4] + pos[5] == a ||
       pos[6] + pos[7] + pos[8] == a || pos[0] + pos[3] + pos[6] == a || pos[1] + pos[4] + pos[7] == a ||
        pos[2] + pos[5] + pos[8] == a || pos[0] + pos[4] + pos[8] == a || pos[2] + pos[4] + pos[6] == a) {
        evaluation += 1;
    }
    //Take victories
    a = -3;
    if(pos[0] + pos[1] + pos[2] == a || pos[3] + pos[4] + pos[5] == a ||
       pos[6] + pos[7] + pos[8] == a || pos[0] + pos[3] + pos[6] == a || pos[1] + pos[4] + pos[7] == a ||
        pos[2] + pos[5] + pos[8] == a || pos[0] + pos[4] + pos[8] == a || pos[2] + pos[4] + pos[6] == a) {
        evaluation += 5;
    }

    //Block a players turn if necessary
    pos[square] = player;

    a = 3;
    if(pos[0] + pos[1] + pos[2] == a || pos[3] + pos[4] + pos[5] == a ||
        pos[6] + pos[7] + pos[8] == a || pos[0] + pos[3] + pos[6] == a ||
        pos[1] + pos[4] + pos[7] == a ||
        pos[2] + pos[5] + pos[8] == a ||
        pos[0] + pos[4] + pos[8] == a ||
        pos[2] + pos[4] + pos[6] == a) {
        evaluation += 2;
    }

    pos[square] = ai;

    evaluation-= checkWinCondition(pos)*15;

    pos[square] = 0;

    return evaluation;
}


void play_game(){

    while(checkWinCondition(mainBoard)==0){
        if(currentTurn==-1){
            int mx = 0, bestMove = -1;

            for ( int i = 0; i < 9; i++){
                if(mainBoard[i]!=0) continue;

                int eval = evaluatePos(mainBoard, i);

                if(eval > mx){
                    mx = eval;
                    bestMove = i;
                }
            }
            mainBoard[bestMove] = -1;
            currentTurn = -currentTurn;
        }else{
            int square;

            cout <<"Enter square: ";
            cin >> square;
            mainBoard[square] = 1;
            currentTurn = -currentTurn;
        }
        print_board(mainBoard);

    }

}


int main(){
    print_board(mainBoard);
    play_game();
}
