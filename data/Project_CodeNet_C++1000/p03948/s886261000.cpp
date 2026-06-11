#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int a[100005];
void solve(){
    int n;
    cin>>n;
    int t;
    cin>>t;
    int profit = 0;
    int mn = 1e9+5;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mn = min(mn,a[i]);
        profit = max(profit,a[i]-mn);
    }
    int ans = 0;
    mn = 1e9+9;
    for(int i=1;i<=n;i++){
        mn = min(mn,a[i]);
        if(profit == a[i]-mn)ans++;
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1;
//	cin>> t;
	while(t--)solve();
	return 0;
}
