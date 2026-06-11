#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod = int(1e9)+7;
using V = vector<ll>;
using P = pair<ll,ll>;

int main()
{
   string s,ans;
   ans= "CODEFESTIVAL2016";
   cin >>s;ll a=0;
   rep(i,s.size()){
    if(s[i]!=ans[i])a++;
   }
   cout << a << endl;
    return 0;
}
