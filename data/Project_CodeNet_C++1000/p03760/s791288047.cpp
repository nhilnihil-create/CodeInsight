#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define f first
#define s second
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007

typedef long long ll;


void solve()
{
    string o,e;
    cin>>o>>e;

    for(int i=0;i<o.size();++i){
        if(i==e.size())cout<<o[i]<<endl;
        else cout<<o[i]<<e[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //int t;
    //cin>>t;
    //while(t--)
    solve();
    return 0;
}
