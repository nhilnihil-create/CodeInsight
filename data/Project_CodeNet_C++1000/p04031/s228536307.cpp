//#pragma GCC optimize(\"Ofast,no-stack-protector\")
//#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx\")
//#pragma GCC target(\"avx,tune=native\")
// Neil

#include<bits/stdc++.h>

using namespace std;

typedef complex<double> base;
typedef long double ld;
typedef long long ll;

#define endl "\n"
#define pb push_back
#define pii pair<int,int>
#define pll pair< ll , ll >
#define vi vector<int>
#define vvi vector< vi >
const int MAXN=(int)(2e5+5);
const ll MOD=(ll)(1e9+7);
int t;
int arr[MAXN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;
    cin>>n;
    ll s = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        s+=arr[i];
    }
    ll a = (ll)s/n;
    
    if(s%n == 0){
        int cost = 0;
        for(int i=0;i<n;i++){
            cost += 1ll*(arr[i]-a) * (arr[i]-a);
        }
        cout<<cost<<endl;
    }
    else{
        int cost1 = 0, cost2 = 0;
        for(int i=0;i<n;i++){
            cost1 += 1ll*(arr[i]-a) * (arr[i]-a);
        }
        a++;
        for(int i=0;i<n;i++){
            cost2 += 1ll*(arr[i]-a) * (arr[i]-a);
        }
        cout<<min(cost1, cost2)<<endl;
    }
    return 0;
}