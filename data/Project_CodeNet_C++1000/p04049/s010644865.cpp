#include <bits/stdc++.h>
using namespace std;

#ifdef ENABLE_DEBUG
#define DEBUG(a) cerr<<#a<<"="<<a<<endl
#define DEBUG_ARRAY(a,n) cerr<<#a<<"["<<n<<"]="<<a[n]<<endl
#else
#define DEBUG(a) 
#define DEBUG_ARRAY(a,n) 
#endif
#define FOR(i, a, b) for(int i = a;i < b;i++)
#define For(i, a) FOR(i, 0, a)
#define REV(i, a, b) for(int i = b-1;i >= a;i--)
#define Rev(i, a) REV(i, 0, a)
#define REP(a) For(i, a)

typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> P;
typedef pair<ll,P> PP;
typedef vector<ll> vll;

const ll INF=(1LL<<50);

vector<ll> m[2000];
bool used[2000];

void solve(long long N, long long K, std::vector<long long> A, std::vector<long long> B){
    ll ans=INF;
    for(ll i = 0; i < N-1; i++)
    {
        m[A[i]].push_back(B[i]);
        m[B[i]].push_back(A[i]);
    }
    if(K%2==0){
        for(ll i = 0; i < N; i++)
        {
            DEBUG(i);
            ll num_used=0;
            queue<P> q;
            fill(used,used+2000,false);
            q.push(P(i,0));
            used[i]=true;
            num_used++;
            while(!q.empty()){
                P cur=q.front();q.pop();
                for(auto v:m[cur.first]){
                    if(used[v]==false&&cur.second<K/2){
                        used[v]=true;
                        num_used++;
                        q.push(P(v,cur.second+1));
                        DEBUG(v);
                    }
                }
            }
            ans=min(ans,N-num_used);
            DEBUG(N-num_used);
        }
    }else{
        for(ll i = 0; i < N-1; i++)
        {
            DEBUG(i);
            ll num_used=0;
            fill(used,used+2000,false);
            queue<PP> q;
            q.push(PP(0,P(A[i],B[i])));
            num_used++;
            while(!q.empty()){
                auto cur=q.front();q.pop();
                for(auto e:m[cur.second.first])
                {
                    if(e!=cur.second.second&&cur.first<(K-1)/2){
                        num_used++;
                        DEBUG(e);
                        q.push(PP(cur.first+1,P(e,cur.second.first)));
                    }
                }
                if(cur.second.first==A[i]&&cur.second.second==B[i]){
                    for(auto e:m[cur.second.second])
                    {
                        if(e!=cur.second.first&&cur.first<(K-1)/2){
                            num_used++;
                            DEBUG(e);
                            q.push(PP(cur.first+1,P(e,cur.second.second)));
                        }
                    }
                }
            }
            DEBUG(N-1-num_used);
            ans=min(ans,N-1-num_used);
        }
    }
    cout<<ans<<endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> A(N-1);
    std::vector<long long> B(N-1);
    for(int i = 0 ; i < N-1 ; i++){
        scanf("%lld",&A[i]);
        scanf("%lld",&B[i]);
        A[i]--;
        B[i]--;
    }
    solve(N, K, std::move(A), std::move(B));
    return 0;
}
