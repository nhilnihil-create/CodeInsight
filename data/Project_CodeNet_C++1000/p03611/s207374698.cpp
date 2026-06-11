#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define vi vector<int>
template <class t, class u>
void chmax(t &a, u b)
{
    if (a < b)
        a = b;
}
template <class t, class u>
void chmin(t &a, u b)
{
    if (b < a)
        a = b;
}

int main()
{
    map<int,int> m;
    int n;
    cin>>n;
    for (size_t i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        m[a-1]++;
        m[a]++;
        m[a+1]++;
    }
    int ans=0;
    for(auto &i:m){
        chmax(ans, i.second);
    }
    cout << ans << endl;

    return 0;
}