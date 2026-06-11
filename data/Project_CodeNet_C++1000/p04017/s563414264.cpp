#include<bits/stdc++.h>
//using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define per(i,j,n) for(int i=(int)(j);(int)(n)<=i;i--)
#define ll long long
#define ALL(a) (a).begin(),(a).end()
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(ll)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(ll)(key)))
#define pb push_back
#define mp make_pair
#define endl "\n"
using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::string;
using std::upper_bound;
using std::lower_bound;
using vi=vector<ll>;
using vii=vector<vi>;
using pii=pair<ll,ll>;
const ll MOD=1e9+7;
const int MAX=1e5+1;
const ll INF=(1ll<<62)-1;
signed main(){
    int N,L,Q; cin>>N;
    vi Point(N);
    rep(i,0,N) cin>>Point[i];
    vii dp(N,vi (60));
    Point.pb(INF);
    cin>>L>>Q;
    rep(i,0,N){
        dp[i][0]=disup(Point,Point[i]+L)-1;
    }
    rep(i,1,60){
        rep(j,0,N){
            dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }
    rep(_,0,Q){
        int Start,Goal; cin>>Start>>Goal;
        if(Start>Goal) std::swap(Start,Goal);
        int ans=0;
        Start--;
        Goal--;
        while(1){
            int Dist=dislow(dp[Start],Goal);
            if(Dist==0){
                ans++;
                break;
            }
            Start=dp[Start][Dist-1];
            ans+=(1ll<<(Dist-1));
        }
        cout<<ans<<endl;
    }
}
 