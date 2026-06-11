#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod = int(1e9)+7;
using V = vector<ll>;
using P = pair<ll,ll>;


int main(){
   ll a,b;cin >>a>>b;
   if(a*b<=0){
       puts("Zero");
       return 0;
   }
   if(a>0){
       puts("Positive");
       return 0;
   }
   if(a<0){
       if((b-a)%2==0)puts("Negative");
       else puts("Positive");
       return 0;
   }
    return 0;
}