#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
typedef vector<int>         vi;
const int mod = 1000000007;


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a,b;
    cin>>n>>a>>b;
    int arr[n];
    vi v;
    cin>>arr[0];
    for(int i =1;i<n;i++){
        cin>>arr[i];
        v.pb(arr[i]-arr[i-1]);
    }
    int ans = 0;
    for(int i =0;i <v.size();i++){
        if( v[i]*a < b){
            ans = ans + v[i]*a;
        }
        else{
            ans = ans + b;
        }


    }
    cout<<ans<<endl;








}












