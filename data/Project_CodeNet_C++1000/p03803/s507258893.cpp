#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using ll=long long;
using namespace std;
int main(){
 int a,b;
 cin>>a>>b;
 if(a==1 ) a+=13;
 if (b==1) b+=13;
 if(a<b) cout<<"Bob"<<endl;
 else if(a>b) cout<<"Alice"<<endl;
 else cout<<"Draw"<<endl;
 }

