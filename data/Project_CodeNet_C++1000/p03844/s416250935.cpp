#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define fast_io;                    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll MAXN=1e6 + 10;
const ll LOG=22;
const ll INF=8e18;
const ll MOD=1e9 + 7; // 998244353; // 1e9 + 9;
int main(){
fast_io;
int a,b;
char c;
cin>>a>>c>>b;
if(c=='+'){
      cout<<a+b;
      return 0;
}
cout<<a-b;
return 0;
}
