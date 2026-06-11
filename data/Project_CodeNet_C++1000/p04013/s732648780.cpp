#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<iomanip>


#define MOD 1000000007
#define INF 1001001001
#define MIN -1001001001
#define rep(i,k,N) for(int i=k;i<N;i++)
#define MP make_pair
#define MT make_tuple //tie,make_tuple は別物
#define PB push_back
#define PF push_front
#define all(x) (x).begin(),(x).end()


using namespace std;
typedef long long ll;
typedef vector<ll> v;
typedef vector<vector<ll>> vv;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    ll N,A;
    cin>>N>>A;
    v x(N);
    v p,m,z;
    rep(i,0,N){
        cin>>x[i];x[i]-=A;
        if(x[i] > 0)p.PB(x[i]);
        if(x[i] == 0)z.PB(x[i]);
        if(x[i] < 0)m.PB(-x[i]);
    }
    sort(all(p));
    sort(all(m));
    v p_sum(2501);
    v m_sum(2501);
    p_sum[0] = 1;
    m_sum[0] = 1;
    rep(i,0,p.size()){
       for(ll j = 2500; j>=0; j--){
            if(j+p[i] <= 2500)p_sum[j+p[i]] += p_sum[j];
        }
    }
    rep(i,0,m.size()){
        for(ll j = 2500; j>=0; j--){
            if(j+m[i] <= 2500)m_sum[j+m[i]] += m_sum[j];
        }
    }
    ll zN = z.size();
    ll n2 = 1;
    rep(i,0,zN)n2 *= 2;
    ll ans = 0;
    rep(i,1,2501){
        ans += p_sum[i] * m_sum[i];
    }
    cout<<n2-1 + n2 * ans;
    return 0;
}