#include <bits/stdc++.h>
using namespace std;


int main() {
int N,M;
cin>>N>>M;
vector<long> a(M);
vector<long> b(M);
vector<long> c(M);
for(int i=0;i<M;i++){
  int x,y,z;
  cin>>x>>y>>z;
  x--,y--;
  a[i]=x,b[i]=y,c[i]=z;
}
vector<vector<long>> d(N,vector<long>(N));

for(int i=0;i<N;i++) for(int j=0;j<N;j++)  if(i!=j) d[i][j]=1234567890;

for(int i=0;i<M;i++){
  d[a[i]][b[i]]=c[i];
  d[b[i]][a[i]]=c[i];
}

for(int k=0;k<N;k++) for(int i=0;i<N;i++) for(int j=0;j<N;j++){
  d[i][j]=min(d[i][k]+d[k][j],d[i][j]);
}
long ans=0;

for(int i=0;i<M;i++){
  if(d[a[i]][b[i]]!=c[i]){
    ans++;
  }
}
cout<<ans<<endl;

}
