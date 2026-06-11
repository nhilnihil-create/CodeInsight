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
   V a(3);rep(i,3)cin >>a[i];
   sort(all(a));
   bool flg=false;
   if(a[2]==a[1]+a[0])flg=true;
   if(flg)puts("Yes");
   else puts("No");
    return 0;
}
