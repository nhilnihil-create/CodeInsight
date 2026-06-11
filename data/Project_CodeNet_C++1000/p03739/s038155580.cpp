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

    ll n;cin>>n;
    vector<ll> a(n);
    vector<ll> sum(n);

    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    ll c1=0;

    for(int i=0;i<n;i++){
        if(i==0) sum[i] = a[i];
        else sum[i]=sum[i-1]+a[i];

        if(i%2==0 && sum[i]<=0){
            c1 += abs(sum[i])+1;
            sum[i]=1;
        }
        else if(i%2==1 && sum[i]>=0){
            c1+= abs(sum[i])+1;
            sum[i]=-1;
        }

    }

    ll c2=0;

    for(int i=0;i<n;i++){
        if(i==0) sum[i] = a[i];
        else sum[i]=sum[i-1]+a[i];

        if(i%2==0 && sum[i]>=0){
            c2 += abs(sum[i])+1;
            sum[i]=-1;
        }
        else if(i%2==1 && sum[i]<=0){
            c2+= abs(sum[i])+1;
            sum[i]=1;
        }

    }

    cout<<min(c1,c2)<<endl;

}
