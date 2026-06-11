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
int N;
P p[500];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    rep(i,0,N){
        int x;
        cin>>x;
        p[i]=P(x,i+1);
    }
    sort(p,p+N);
    ll pos=0;
    rep(i,0,N){
        pos+=p[i].sc;
        if(p[i].fr<pos){
            cout <<"No"<<"\n";
            return 0;
        }
    }
    pos=0;
    rer(i,N,0){
        pos+=N+1-p[i].sc;
        if(N*N-p[i].fr+1<pos){
            cout <<"No"<<"\n";
            return 0;
        }
    }
    cout <<"Yes"<<"\n";
    vector<int> ans(N*N,0);
    rep(i,0,N){
        ans[p[i].fr-1]=p[i].sc;
    }
    pos=0;
    rep(i,0,N){
        int j=p[i].sc-1;
        while(j){
            if(ans[pos]!=0){
                pos++;
                continue;
            }
            ans[pos]=p[i].sc;
            pos++;
            j--;
        }
    }
    pos=N*N-1;
    rer(i,N,0){
        int j=N-p[i].sc;
        while(j){
            if(ans[pos]!=0){
                pos--;
                continue;
            }
            ans[pos]=p[i].sc;
            pos--;
            j--;
        }
    }
    rep(i,0,N*N){
        if(i==N*N-1) cout<<ans[i]<<"\n";
        else cout<<ans[i]<<" ";
    }
}