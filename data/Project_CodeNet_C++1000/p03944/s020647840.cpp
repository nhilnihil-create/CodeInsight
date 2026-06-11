#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int W, H, N;
  cin >> W >> H >> N;
  vector<int> Waxis(W+1,0);
  vector<int> Haxis(H+1,0);
  vector<vector<int>> grid(N, vector<int>(3,0));
  
  for (int i =0; i< N ; i++){
    for (int j=0 ; j < 3; j++){
      cin >> grid.at(i).at(j);
    }
  }
/*imptest
  cout << W << " " << H << " " << N << endl;
  for (int i =0; i< N ; i++){
    for (int j=0; j < 3; j++){
      cout << grid.at(i).at(j)<< " ";
    }
    cout << endl;
  }
*/ 
  for (int i=0; i< N; i++){
    if(grid.at(i).at(2) == 1){//xより小さいところを塗る
      for (int j = 0; j < grid.at(i).at(0) ;j++){
        Waxis.at(j)++;
      }
    }
    else if(grid.at(i).at(2) == 2){//xより大きいところ
      for (int j = grid.at(i).at(0)+1 ; j<W+1 ;j++){
        Waxis.at(j)++;
      }
    }
    else if(grid.at(i).at(2) == 3){//yより小さいところ
      for (int j = 0; j < grid.at(i).at(1) ;j++) {
        Haxis.at(j)++;
      }
    }
    else if(grid.at(i).at(2) == 4){
      for (int j = grid.at(i).at(1)+1 ; j<H+1 ;j++){
        Haxis.at(j)++;
      }
    }
  }

    int Hcount =0;
    int Wcount =0;
    for (int i =0; i< W+1; i++){
//      cout << Waxis.at(i) << " ";
      if(Waxis.at(i)==0) Wcount++;
    }
//    cout << endl;
    for (int i =0; i< H+1; i++){
//      cout << Haxis.at(i) << " ";
      if(Haxis.at(i)==0) Hcount++;
    }
//    cout << endl;
    if(Wcount ==0 || Hcount == 0) cout << 0 << endl;
    else cout << (Wcount-1) * (Hcount-1) << endl;

}
//  cout << Waxis.at(5) << endl;
