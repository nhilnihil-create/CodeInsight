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
    
    ll n,t;
    cin>>n>>t;

    vector<ll> ti(n);

    for(int i=0;i<n;i++){
        cin>>ti[i];
    }

    ll c=0,time=0;

    for(int i=0;i<n-1;i++){
        if(ti[i]+t>ti[i+1]){
            time+=ti[i+1]-ti[i];
        }else{
            time+=t;
        }
    }

    cout<<time+t<<endl;

}
