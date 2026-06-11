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
   int n;cin >>n;
   vector<int>t(n);
   int sum=0;
    for (int i = 0; i < n; ++i) {
        cin >>t[i];
        sum+=t[i];
    }
    int m;cin >>m;
    int d=0;
    for (int i = 0; i < m; ++i) {
        int p,x;cin >>p>>x;
        p--;
        d=t[p]-x;
        cout <<sum-d<<endl;
    }
}
