#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define pii make_pair
int ceil(int a, int b) { if(a%b==0) return a/b; else return a/b+1; }

main()
{
    //fastio;
    int n;
    cin>>n;
    int a[n];
    vector<int>v;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);
    for(int i=n-1; i>=1; i--) {
        if(a[i]==a[i-1]) {
            v.push_back(a[i]);
            i--;
        }
    }
    if(v.size()<2) cout<<"0";
    else cout<<v[0]*v[1];
}
