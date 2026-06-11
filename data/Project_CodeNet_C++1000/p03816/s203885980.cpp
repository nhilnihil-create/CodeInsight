#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const int N = 3e5+6;
const int mod = 1e9+7;
const int inf = 1e8;
int cnt[N];
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }
    int ans = 0;
    for(int i=0;i<N;i++){
        ans+=max(0,cnt[i]-1);
    }
    if(ans%2)ans++;
    cout<<n-ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--)solve();
    return 0;
}
