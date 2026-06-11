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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin>>N;
    vector<int> a(N,0);
    rep(i,0,N) cin>>a[i];
    sor(a);
    if(N==2){
        if(a[0]==1&&a[1]==1) cout <<"Possible"<<"\n";
        else cout <<"Impossible"<<"\n";
    }
    else if(a[N-1]%2){
        if(!(a[0]==(a[N-1]+1)/2&&a[1]==a[0]&&a[2]!=a[1])) cout <<"Impossible"<<"\n";
        else{
            rep(i,(a[N-1]+1)/2, a[N-1]+1){
                if(ub(a,i)-lb(a,i)<2){
                    cout <<"Impossible"<<"\n";
                    return 0;
                }
            }
            cout <<"Possible"<<"\n";
        }
    }
    else{
        if(!(a[0]==a[N-1]/2&&a[1]!=a[0])) cout <<"Impossible"<<"\n";
        else{
            rep(i,a[N-1]/2+1, a[N-1]+1){
                if(ub(a,i)-lb(a,i)<2){
                    cout <<"Impossible"<<"\n";
                    return 0;
                }
            }
            cout <<"Possible"<<"\n";
        }
    }
}