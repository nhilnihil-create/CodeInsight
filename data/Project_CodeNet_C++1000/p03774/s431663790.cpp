#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

int main() {
 int N,M;
 cin>>N>>M;
 int a[100];
 int b[100];
 int c[100];
 int d[100];
 for(int i=0;i<N;i++){
     cin>>a[i]>>b[i];
 }
 for(int i=0;i<M;i++){
     cin>>c[i]>>d[i];
 }
 for(int i=0;i<N;i++){
     int m=999999999;int r=0;;
     for(int j=0;j<M;j++){
      int h=abs(c[j]-a[i])+abs(d[j]-b[i]);
      if(m>h){r=j+1;m=h;}
     }
     cout<<r<<endl;
 }
 return 0;
}