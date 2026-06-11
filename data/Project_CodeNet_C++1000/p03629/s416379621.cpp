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
string S,T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

vector<int> ansint((2e+5)/26 + 2,-1);
vector<vector<bool> > sub2((2e+5)/26 + 2,vector<bool>(26*26,false));
vector<vector<bool> > memo((2e+5)/26 + 2,vector<bool>(26,false));
ll ans = 1;
bool dfs(int id, int abc){ //true -> その後の文字を取れる
    if(memo[id][abc]) return false;
    if(id == ans - 1) {
        ansint[id] = abc;
        return true;
    }
    rep(i,26){
        if(sub2[id][abc*26 + i]) continue;
        if(dfs(id+1 ,i)){
            ansint[id] = abc;
            return true;
        }
    }
    memo[id][abc] = true;
    return false;
}

int main() {
    cin>>S;
    N = S.size();
    set<int> alpha;
    vector<int> sint(N);
    rep(i,N) sint[i] = S[i] - 'a';
    rep(i,N){
        for(int fst : alpha) sub2[ans - 1][fst*26 + sint[i]] = true;
        alpha.insert(sint[i]);
        if(alpha.size() == 26){
            alpha.clear();
            ++ans;
        }
    }
    for(int al : alpha) memo[ans - 1][al] = true;
    rep(i,26){
        if(dfs(0,i)) break;
    }
    rep(i,ans) cout<<char(ansint[i] + 97);
    cout<<endl;
}