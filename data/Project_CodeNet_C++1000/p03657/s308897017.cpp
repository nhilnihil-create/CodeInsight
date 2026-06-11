#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
   ll a,b;cin >>a>>b;
   bool flg=false;
   if(a%3==0||(a+b)%3==0||b%3==0)flg=true;
   if(flg)puts("Possible");
   else puts("Impossible");
   return 0;
}