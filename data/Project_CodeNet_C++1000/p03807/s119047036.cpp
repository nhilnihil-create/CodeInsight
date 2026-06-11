#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
  ll n;cin>>n;
  ll odd=0;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        if (a % 2 == 1)odd++;
    }
    if(odd%2==0)puts("YES");
    else puts("NO");
  return 0;
}

