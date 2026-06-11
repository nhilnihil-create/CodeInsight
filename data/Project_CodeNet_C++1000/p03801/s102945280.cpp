#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,L,R;
string S, T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

int main() {
    cin>>N;
    vec a(N);
    ll sum = 0;
    rep(i,N) {
        cin>>a[i];
        sum += a[i];
    }
    vec id(1, 0), ele(1, a[0]);
    ll last = a[0];
    reps(i,1,N){
        if(last < a[i]){
            id.push_back(i);
            ele.push_back(a[i]);
            last = a[i];
        }
    }
    vec num_plus(id.size(), 1);
    vec ans(N,0);
    rep(i, id.size()){
        ll lb = id[i], ub = (i == id.size() - 1 ? N : id[i+1]);
        reps(j, lb + 1, ub){
            auto ite = upper_bound(ele.begin(), ele.end(), a[j]);
            if(ite != ele.begin()) {
                ll index = ite - ele.begin();
                --ite;
                ans[id[index]] += a[j] - *ite;
                ++num_plus[index];
                //cout << j << ' ' << *ite << endl;
            }
        }
    }
    ll num = 1;
    /*rep(i,N) cout<<ans[i]<<' ';
    cout<<endl;
    rep(i,id.size()) cout<<num_plus[i]<<' ';
    cout<<endl;*/
    for(int i = id.size() - 1; i >= 0; --i){
        if(i == 0){
            ans[0] = sum;
        }else{
            ans[id[i]] += (ele[i] - ele[i-1]) * num;
            num += num_plus[i];
            sum -= ans[id[i]];
        }
    }
    rep(i,N) cout<<ans[i]<<endl;
}