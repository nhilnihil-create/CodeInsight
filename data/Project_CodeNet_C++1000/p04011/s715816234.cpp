#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define pii make_pair
int ceil(int a, int b) { if(a%b==0) return a/b; else return a/b+1; }

main()
{
    //fastio;
    int n, k, x, y;
    cin>>n>>k>>x>>y;
    int rem=max(0LL, n-k);
    int mn=min(n, k);
    cout<<mn*x+rem*y;
}
