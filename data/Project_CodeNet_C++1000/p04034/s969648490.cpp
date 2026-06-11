#include<bits/stdc++.h>
using namespace std;
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define SZ(x) ((int)(x).size())
#define debug(x) cerr << #x << ": " << x << '\n'
const char newl = '\n';
typedef long long int Int;
typedef pair<int,int> P;
using ll = long long;
using VI = vector<int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const long long INF = 1LL<<60;

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> nums(N,1),can(N,0);
    can[0] = 1;
    for(int i=0;i<M;i++){
        int a,b;cin >> a >> b;
        a--,b--;
        if(can[a]) can[b] = 1;
        if(nums[a]==1) can[a] = 0;
        nums[a]--;
        nums[b]++; 
    }
    int res = 0;
    rep(i,N) if(can[i]&&nums[i]) ++res;
    cout << res << endl;
}