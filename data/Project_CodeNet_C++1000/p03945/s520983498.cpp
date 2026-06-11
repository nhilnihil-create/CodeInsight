#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
   string s;cin >>s;
   ll n=s.size();
   char now=s[0];
   ll ans=0;
    for (int i = 0; i < n; ++i) {
        if(s[i]!=now){
            ans++;
            if(s[i]=='B')now='B';
            else now='W';
        }
    }
    cout <<ans <<endl;
    return 0;
}

