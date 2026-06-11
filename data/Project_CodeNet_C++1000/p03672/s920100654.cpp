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
    string s;cin >>s;
    int ans=0;
    int n=s.size();
    for (int i = 0; i < n-1; i++) {
        s.pop_back();
        if(s.size()%2!=0)continue;
        string f,b;
        int k=s.size();
        f=s.substr(0,k/2);
        b=s.substr(k/2,n);
        if(f==b)ans=max(ans,k);
    }
    cout <<ans <<endl;
    return 0;
}