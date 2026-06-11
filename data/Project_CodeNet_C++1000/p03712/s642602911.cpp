    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      int H,W;
      cin >> H >> W;
      vector<vector<char>> Sh(H+2,vector<char>(W+2));//初期化されてる
      
      for(int i=0;i<H+2;i++){
        for(int j=0;j<W+2;j++){
          if(i==0 || i==H+1 || j==0 || j==W+1){
            Sh[i][j]='#';
          }else{
            cin >> Sh[i][j];
          }
          cout << Sh[i][j];
        }
        cout << endl;
      }
      
    }