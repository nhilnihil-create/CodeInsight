# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
ll n,arr[400005];
ll ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=3*n;i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+3*n+1);
    for(int i=1;i<=n;i++){
        int idx=i*2;
        ans+=arr[3*n-idx+1];
    }
    cout<<ans<<endl;
}