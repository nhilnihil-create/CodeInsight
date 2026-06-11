#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
  const int MAX = 110000;
  int N, M;
  int res = 0;
  vector<int> X, con;
  vector<pair<int,int>> modM;

  cin>>N>>M;

  X.resize(N);
  con.resize(MAX);
  modM.resize(M);

  for(int i = 0; i < N; i++){
    cin>>X[i];
    con[X[i]]++;
  }

  for(int i = 0; i < MAX; i++){
    modM[i%M].first += con[i]%2;
    modM[i%M].second += con[i]/2;
  }

  for(int i = 0; i * 2 <= M; i++){
    if(i == 0 || (M%2 == 0 && i == M/2)) {
      res += modM[i].second + modM[i].first / 2;
    } else {
      int mino = min(modM[i].first, modM[M-i].first);

      res += mino;

      modM[i].first -= mino;
      modM[M-i].first -= mino;

      //cout<<"A "<<mino<<endl;

      if(modM[i].first){
        mino = min(modM[i].first/2, modM[M-i].second);
        res += mino * 2;
        //cout<<"B "<<mino<<endl;
        modM[M-i].second -= mino;
      }
      if(modM[M-i].first) {
        mino = min(modM[M-i].first/2, modM[i].second);
        res += mino * 2;
        //cout<<"C "<<mino<<endl;
        modM[i].second -= mino;
      }

      res += modM[i].second + modM[M-i].second;
    }
    //cout<<"i = "<<i<<" res = "<<res<<endl;
  }

  cout<<res<<endl;

  return 0;
}
