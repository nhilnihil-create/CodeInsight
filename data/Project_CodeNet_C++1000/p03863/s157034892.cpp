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
    string s;cin >>s;
    ll n=s.size();
    bool flg=true;
    if(s[0]==s[n-1]&&n%2!=0)flg=false;
    if(s[0]!=s[n-1]&&n%2==0)flg=false;
    if(flg)puts("First");
    else puts("Second");
    return 0;
}