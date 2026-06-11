#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod = int(1e9)+7;
using V = vector<int >;
using P = pair<int,int>;

int main()
{
    int a,b;cin >>a>>b;
    int sum=a+b;
    if(sum>=10)puts("error");
    else cout <<sum<< endl;
    return 0;
}
