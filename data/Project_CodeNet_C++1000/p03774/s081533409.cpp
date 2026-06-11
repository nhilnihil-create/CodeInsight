#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  cin >> N >> M;
  int a[51],b[51];
  for(int i = 0;i<N;i++){
    cin >> a[i] >> b[i] ;
  }
  int c[51],d[51];
  for(int i = 1 ; i<=M;i++){
    cin >> c[i] >>d[i] ;
  }
  int g[51];
  for(int i = 0; i<N; i++){
    int ans = 800000000;
    for(int j = M; j>0;j--){
      int e = c[j];
      int f = d[j];
      int d = abs(a[i]-e)+abs(b[i]-f);
      if(ans >= d){
      ans = d;
      g[i] = j;
    }
  }
}
for(int i =0; i <N; i++){
  cout << g[i] << endl;
}
}