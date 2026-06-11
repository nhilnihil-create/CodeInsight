#include <iostream>
#include <vector>
#define NtoM(N, M) for(int i=N;i<M;i++)
#define Nfor(N) for(int j=0;j<N;j++)

using namespace std;

int main(){
  	int W, H, N;
  	cin >> W >> H >> N;
  	vector<vector<int>> board(W, vector<int>(H));
  	for(int k=0;k<N;k++){
      	int x, y, a;
      	cin >> x >> y >> a;
      	switch(a){
          case 1:
            	NtoM(0, x){
                  	Nfor(H) board[i][j] = 1;
                }
            	break;
          case 2:
            	NtoM(x, W){
                  	Nfor(H) board[i][j] = 1;
                }
            	break;
          case 3:
            	NtoM(0, y){
                  	Nfor(W) board[j][i] = 1;
                }
            	break;
          case 4:
            	NtoM(y, H){
					Nfor(W) board[j][i] = 1;
                }
            	break;
        }
    }
  	int sum = 0;
  	NtoM(0, W){
      	Nfor(H){
          	if(board[i][j] == 0) sum++;
        }
    }
  	cout << sum << endl;
}
