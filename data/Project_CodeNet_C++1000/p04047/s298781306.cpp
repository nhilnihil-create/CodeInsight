#include <bits/stdc++.h>
using namespace std;
    
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i, n) for (int i = 0; i < n; i++)
#define repn(i, a, b) for (int i = a;i<=b;i++)
#define ll long long int
#define pb push_back
#define mpi map<int,int>
#define mpl map<ll,ll>
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mem(x,val) memset(x, val, sizeof(x))
#define ritr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define pai pair < int, int> 
#define pal pair < ll, ll> 
#define vi vector <int> 
#define vl vector < ll > 
#define vpai vector < pii > 

const int mod = 1e9+7;
const int INF = INT_MAX;
const int sze = 3005;

void solve() {
    int n;
    cin>>n;
    vi arr(2*n,0);
    ll sum=0;
    rep(i,2*n) cin>>arr[i];
    sort(all(arr));
    rep(i,2*n){
        sum+=arr[i];
        i++;
    }
    cout<<sum<<endl;
}

int main() {
    IOS;

    int t = 1;
    //cin >> t;
    while (t--) {
       solve();
    }

  return 0;
}