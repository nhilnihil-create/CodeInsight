#include<bits/stdc++.h>
using namespace std;
int main(){
  long N;cin>>N;
  vector<long>A(N-1);for(int i=0;i<N-1;i++)cin>>A[i];
  vector<vector<long>>T(N);//有向グラフ; 勝った人から負けた人へ
  for(long i=0;i<N-1;i++)T[A[i]-1].push_back(i+1);
  vector<pair<long,long>>D(N);D[0]=pair<long,long>(0,0);//1からの距離=深さ/i
  queue<long>q;q.push(0);
  while(q.size()){
    long f=q.front();q.pop();
    for(long n:T[f]){
      D[n].first=D[f].first+1;
      D[n].second=n;
      q.push(n);
    }
  }
  vector<long>H(N,0);//下から統合するように
  sort(D.begin(),D.end(),greater<pair<long,long>>());
  for(long i=0;i<N;i++){
    long n=D[i].second;
    vector<long>C;
    for(long c:T[n])C.push_back(H[c]);
    sort(C.begin(),C.end(),greater<long>());
    
    for(long j=0;j<C.size();j++){
      H[n]=max(H[n],C[j]+j+1);
    }
  }
  cout<<H[0];
}
/*




*/