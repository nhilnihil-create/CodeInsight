#include<bits/stdc++.h>
//#include<iostream>

//#include<vector>
//#include<iterator>
//#include<utility>
//#include<algorithm>
//#include<cmath>
using namespace std;


#define ll long long
#define fr(m) for(int i=0; i<m; i++)
#define frj(m) for(int j=0; j<m; j++)
#define frr(n) for(int i=n; i>=0; i--)
#define pb push_back
#define orr ||
#define nl \n
#define sci(n) scanf("%lld ", &n)
#define pri(n) printf("%d", n)
#define prl(n) printf("%lld", n)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

bool compare(ll a, ll b){
    return(a>b);
}

int main()
{

    ll n;
    cin>>n;
    ll arr[n];
    fr(n) cin>>arr[i];
    ll maxi=*max_element(arr,arr+n),mini=*min_element(arr,arr+n),current,sum=0,ans=INT_MAX;
//    cout<<maxi<<" "<<mini<<endl;
    ll a=-100;
    fr(201){
        sum=0;
        current=a++;

        frj(n){
            sum+=(abs(arr[j]-current)*abs(arr[j]-current));
        }
//        cout<<sum<<" "<<current;
         ans=min(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}
