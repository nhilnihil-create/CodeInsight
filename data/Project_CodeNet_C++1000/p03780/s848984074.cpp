#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k; cin>>n>>k;
    vector<int> a(n);
    for(auto& e: a) cin>>e;
    sort(rbegin(a), rend(a));
    
    int res=n;
    long s=0;
    for(int i=0; i<n; ++i) {
        s+=a[i];
        if (s>=k) { res=min(res, n-i-1); s-=a[i]; }
    }
    cout<<res<<endl;
}