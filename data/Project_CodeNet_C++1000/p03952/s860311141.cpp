#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#include<list>
#include<unordered_map>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define INF (1 << 30) - 1
#define LLINF (1LL << 61) - 1
// #define int ll
using namespace std;
const int MOD = 1000000007;
const int MAX = 510000;
 
 
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,x,ans[299919];
    cin>>n>>x;
    if(x==1 ||x==2*n-1){
        cout<<"No"<<endl;
        return 0;
    }
    if(x==2*n-2){
        ans[n-2]=2*n-3;
        ans[n-1]=2*n-2;
        ans[n]=2*n-1;
        ans[n+1]=2*n-4;
        ll now=1;
        rep(i,n-2){
            ans[i]=now;
            now++;
        }
        rep2(i,n+2,2*n-1){
            ans[i]=now;
            now++;
        }
    } else{
        ans[n-2]=x+2;
        ans[n-1]=x-1;
        ans[n]=x;
        ans[n+1]=x+1;
        ll now=1;
        rep(i,n-2){
            if(now>=x-1 && now<=x+2)  now=x+3;
            ans[i]=now;
            now++;
        }
        rep2(i,n+2,2*n-1){
            if(now>=x-1 && now<=x+2)  now=x+3;
            ans[i]=now;
            now++;
        }
    }
    cout<<"Yes"<<endl;
    rep(i,2*n-1) cout<<ans[i]<<endl;
    return 0;
}
