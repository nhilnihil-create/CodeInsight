#include "bits/stdc++.h"
using namespace std;
#define fi first
#define se second
#define ll long long
#define dbg(v) cerr<<#v<<" = "<<v<<'\n'
#define vi vector<int>
#define vl vector <ll>
#define pii pair<int,int>
#define mp make_pair
#define db long double
#define pb push_back
#define all(s) s.begin(),s.end()
const string s = "BYGR";
int main(void)
{
    int n,m,d;
    cin>>n>>m>>d;
    for (int i = 1;i <= n;++i,cout << '\n')
        for (int j = 1;j <= m;++j)
            cout << s[2 * (((i - j + 2 * n * m * d) % (d + d)) < d) + (((i + j) % (d + d)) < d)];
    return 0;
}
