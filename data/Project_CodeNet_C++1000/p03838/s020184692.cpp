#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

int main() {
 int x,y;
 cin>>x>>y;
 int64_t ans=0;
 if(abs(x)==abs(y)&&x!=y){cout<<1<<endl;return 0;}
 if(abs(x)==abs(y)&&x==y){cout<<0<<endl;return 0;}
 if(abs(x)>abs(y)){
     if(x>0){ans++;}
     ans=ans+abs(x)-abs(y);
     if(y>0){ans++;}
     cout<<ans<<endl;return 0;
 }
 if(abs(x)<abs(y)){
     if(x<0){ans++;}
     ans=ans+abs(y)-abs(x);
     if(y<0){ans++;}
     cout<<ans<<endl;return 0;
 }
 return 0;
}