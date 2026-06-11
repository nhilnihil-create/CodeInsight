#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> Pl;
#define all(a) (a).begin(),(a).end()
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(ll i=(a);i<(b);i++)
#define rrep(i,n) for(ll (i)=(n)-1;(i)>=0;i--)
#define SHOW(x) cout << #x << ": " << x << endl;
const ll INF=1e18;
const int iINF = 1e9;
int main(){
    int n,ans,cnt_2 = 0;
    bool flag = false;
    unordered_map<int,int>mp;
    cin>>n;
    ans = n;
    vector<int>a(n);
    rep(i,n){
        cin>>a[i];
        mp[a[i]]++;
    }
    for(auto itr:mp){
        if(itr.second%2 == 1){
            ans -= itr.second - 1;
        }
        else{
            ans -= itr.second - 2;
            cnt_2++;
        }
    }
    ans -= cnt_2 - cnt_2%2;
    if(cnt_2%2 == 1) ans -= 2;
    cout<<ans<<endl;
}
