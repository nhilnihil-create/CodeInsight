# include <bits/stdc++.h>
# define ll int64_t
# define rep(i,n) for(ll i=0;i<n;i++)
# define rrep(i,n) for(ll i=1;i<=n;i++)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define mod 1000000007
#define dump(x) cerr<<#x<<"="<<x<<endl

using namespace std;

bool compare_by_b(pair<string,ll> a,pair<string,ll> b){
    if(a.second != b.second) return a.second<b.second;
    else return a.first<b.first;
}

bool my_compare(pair<string,ll> a,pair<string,ll> b){
    
    if(a.first != b.first) return a.first<b.first;
    if(a.second != b.second) return a.second>b.second;
    else return true;
}

ll factorial(ll n){
    ll x=1;
    rrep(i,n) x*=i;
    return x;
}

ll gcd(ll a,ll b)
{
   if (a%b == 0) return(b);
   else return(gcd(b,a%b));
}

ll lcm(ll a,ll b)
{
   return a/gcd(a,b)*b;
}

void f(ll rest,string s){
    if(rest==0){
        cout<<s<<endl;
    }else{
        for(char c='a';c<='c';c++){
            f(rest -1,s+c);
        }
    }
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n,m,R;
    cin>>n>>m>>R;
    
    vector<vector<ll>> d(n+1,vector<ll>(n+1,1000000000));
    vector<ll> r(R);
    
    rep(i,R) cin>>r[i];
    
    rep(i,m){
        ll x,y; cin>>x>>y;
        ll c; cin>>c;
        d[x][y]=min(d[x][y],c);
        d[y][x]=min(d[y][x],c);
    }
    sort(ALL(r));
    rrep(i,n) d[i][i]=0;
    
    rrep(k,n){
        rrep(i,n){
            rrep(j,n) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        }
    }
    ll ans=1000000000;
    do{
        ll tmp=0;
        rep(i,R-1){
            tmp+=d[r[i]][r[i+1]];
        }
        ans=min(ans,tmp);
    }while(next_permutation(ALL(r)));
    cout<<ans<<endl;
    return 0;
}
