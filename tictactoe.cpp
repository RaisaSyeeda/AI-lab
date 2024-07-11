#include<bits/stdc++.h>
using namespace std;
int arr[4][4]={0};
int f = 0;
int move_count = 0;
int r, c;
void make_move(int r, int c){
    if(f) arr[r][c] = 1;
    else arr[r][c] = 2;
    f^=1;
    for( int i = 1;i <= 3; i++){
        for( int j = 1; j <= 3; j++){
            if(arr[i][j]==0) cout <<"_ ";
            else if(arr[i][j] == 1) cout <<"O"<<" ";
            else cout <<"X"<<" ";
        }
        cout <<endl;
    }
    cout <<endl<<endl;
}
int main(){
    int random = rand()%2;
    if( random){
        make_move(2,2);
        cout <<"Enter Position Row & Column:"<<endl;
        cin >> r >> c;
        make_move(r,c);

    }else{
        cout <<"Enter Position Row & Column:"<<endl;
        cin >> r >> c;
        make_move(r,c);

        if(r==2 && c == 2){
            make_move(1,1);

        }else{
            make_move(2,2);

        }
    }
    while(1){
        int r,c;
        if(f==0){
            cout <<"Possible\n"<< endl;
            int flag = 0;
            for( int i = 1; i <= 3; i++){
                for( int j = 1; j <= 3; j++){
                    if(arr[i][j] == 1){
                        if(arr[i][1]!=2 && arr[i][2]!=2 && arr[i][3]!=2){
                            if(arr[i][1] == 0) {
                                make_move(i,1);
                                flag = 1;
                            }
                            else if(arr[i][2] == 0) {
                                make_move(i,2);
                                flag = 1;
                            }
                            else if( arr[i][3] == 0){
                                make_move(i,3);
                                flag = 1;
                            }
                        }
                        else if(arr[1][j]!=2 && arr[2][j]!=2 && arr[3][j]!=2){
                            if(arr[1][j] == 0) {
                                make_move(1,j);
                                flag = 1;
                            }
                            else if(arr[2][j] == 0) {
                                make_move(2,j);
                                flag = 1;
                            }
                            else if( arr[3][j] == 0){
                                make_move(3,j);
                                flag = 1;
                            }
                        }
                        if(flag) break;
                    }
                    if(flag) break;
                }
                if(flag) break;
            }


        }else{
            cout <<"Enter Position Row & Column:"<<endl;
            cin >> r >> c;

            if(arr[r][c]){
                cout <<"Please Enter In Blank Place."<<endl;
            }else{
                make_move(r, c);
            }


        }

    }
}
