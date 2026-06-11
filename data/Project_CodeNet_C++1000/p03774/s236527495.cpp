#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define f first
#define se second
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007

typedef long long ll;

ll A[51],B[51],C[51],D[51];

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>A[i]>>B[i];
    }
    for(int i=1;i<=m;++i){
        cin>>C[i]>>D[i];
    }
    int ans;
    for(int i=1;i<=n;++i){
        ll small=1e16;
        for(int j=1;j<=m;++j){
            if(abs(A[i]-C[j])+abs(B[i]-D[j])<small){
                small=abs(A[i]-C[j])+abs(B[i]-D[j]);
                ans=j;
            }
        }
        cout<<ans<<endl;
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
