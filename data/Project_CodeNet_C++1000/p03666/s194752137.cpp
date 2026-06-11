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
ll N,A,B,C,D;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>A>>B>>C>>D;
    if(C==0&&D==0){
        if(A==B) cout <<"YES"<<"\n";
        else cout <<"NO"<<"\n";
    }
    else{
        if(N-1>=(B-A+(N-1)*C+C+D-1)/(C+D)&&(B-A+(N-1)*D)/(C+D)>=0&&(B-A+(N-1)*C+C+D-1)/(C+D)<=(B-A+(N-1)*D)/(C+D)) cout <<"YES"<<"\n";
        else cout <<"NO"<<"\n";
    }
}