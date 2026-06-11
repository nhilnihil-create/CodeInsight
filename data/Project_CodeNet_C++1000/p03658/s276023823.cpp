#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int64_t ceil_div(int64_t a, int64_t b) {
    return (a + b - 1) / b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    // int t;cin>>t;

    // while(t--){
    // }

    int n,k;
    cin>>n>>k;
    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int ans=0;

    for(int i=0;i<k;i++){
        ans+=a[i];
    }
    cout<<ans<<endl;
}
