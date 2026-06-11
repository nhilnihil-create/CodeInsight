#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAX = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000000007;

ll N, A, B, ans=0, tmp=0, ave=0;
double ave1;
vector<ll> V;
map<ll,ll> M; 
ll fac[MAX], finv[MAX], inv[MAX];

ll COM(ll n, ll k){
    ll num=1;
    for(int i=0;i<k;i++) {
        num *= n-i;
        num /= (1+i);
    }
    return num;
}

signed main(){
    cin >> N >> A >> B;
    for(int i=0;i<N;i++) {
        ll v;
        cin >> v;
        M[v]++;
        V.push_back(v);
    }
    sort(V.begin(), V.end());
    for(int i=N-1;i>=N-A;i--) {
        ave += V[i];
    }
    ave1 = (double)ave/(double)A;
    ll id1 = lower_bound(V.begin(), V.end(), V[N-A])-V.begin();
    if(id1!=N-A) {
        ll id2 = lower_bound(V.begin(), V.end(), V[N-A]+1)-V.begin();
        ans += COM(id2-id1, id2-(N-A));
        //cout << id2-id1 << " " << id2-(N-A) << " " << COM(id2-id1, id2-(N-A)) << endl;
        if(V[N-A]==V[N-1]) {
            for(int i=N-A-1;i>=max(N-B, id1);i--) {
                tmp = COM(id2-id1, id2-i);
                //if(tmp<0) tmp += MOD;
                ans += tmp;
                //cout << id2-id1 << " " << id2-i << " " << tmp << endl;
            }
        }
    }
    cout << fixed << setprecision(6) << ave1 << endl;
    cout << setprecision(18) << max(1LL, ans) << endl;
    //cout << setprecision(18) << (ll)pow(2,50)-1LL << endl;
    return 0;
}