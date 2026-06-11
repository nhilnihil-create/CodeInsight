#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    ll n,k;
    cin>>n>>k;

    vector<ll> cnt(1e5+1);

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        cnt[a]+=b;
    }
    for(int i=1;i<=1e5;i++){
        if(k<=cnt[i]){
            cout<<i<<endl;
            break;
        }
        k-=cnt[i];
    }

}
