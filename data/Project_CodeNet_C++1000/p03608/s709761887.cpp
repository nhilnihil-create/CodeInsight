#include <bits/stdc++.h>
using namespace std;
    

int main() {
  int N,M,R,Z=2000000000,A=1;
  cin>>N>>M>>R;
  vector<int> q(R);
  vector<int> p(R);
  for(int i=0;i<R;i++){
    cin>>q.at(i);
    q.at(i)--;
    p.at(i)=i;
    A*=(i+1);
  }
  vector<vector<int>> d(N,vector<int>(N,2000000000));
  for(int i=0;i<M;i++){
    int a,b,c;
    cin>>a>>b>>c;
    a--,b--;
    d.at(a).at(b)=c;
    d.at(b).at(a)=c;
  }
  for (int k = 0; k < N; k++){       // 経由する頂点
    for (int i = 0; i < N; i++) {    // 始点
      for (int j = 0; j < N; j++) { // 終点
        if(d.at(i).at(k)!=2000000000&&d.at(k).at(j)!=2000000000){
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
      }
    }
  }
  for(int i=0;i<=A;i++){
    int C=0;
    for(int j=1;j<R;j++){
      C+=d.at(q.at(p.at(j-1))).at(q.at(p.at(j)));
    }
    Z=min(Z,C);
    next_permutation(begin(p),end(p));
  }
  cout<<Z<<endl;
                        
    
}