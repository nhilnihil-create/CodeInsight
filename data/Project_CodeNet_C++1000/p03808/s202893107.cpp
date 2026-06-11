#include <bits/stdc++.h>
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define rer(i, a, b) for(ll i = ll(a) - 1; i >= ll(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
using namespace std;
typedef long long int ll;
typedef pair <int, int> P;

const ll MOD=1000000007;
ll N;
ll A[100000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    ll sum=0;
    rep(i,0,N){
        cin>>A[i];
        sum+=A[i];
    }
    if(sum%((N+1)*N/2)){
        cout <<"NO"<<"\n";
        return 0;
    }
    ll t=sum/((N+1)*N/2);
    ll res=0;
    rep(i,0,N){
        ll d=A[(i+1)%N]-A[i];
        if((t-d)%N||t<d){
            cout <<"NO"<<"\n";
            return 0;
        }
        else{
            res+=(t-d)/N;
        }
    }
    if(res==t) cout <<"YES"<<"\n";
    else cout <<"NO"<<"\n";
}