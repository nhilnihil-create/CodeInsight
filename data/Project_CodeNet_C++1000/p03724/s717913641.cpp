#include<bits/stdc++.h>
using namespace std;
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define SZ(x) ((int)(x).size())
#define debug(x) cerr << #x << ": " << x << '\n'
#define INF 999999999
typedef long long int Int;
typedef pair<int,int> P;
using ll = long long;
using VI = vector<int>;

int N,M;
int main(){
    cin >> N >> M;
    vector<int> a(N);
    rep(i,M){
        int n,m;cin >> n >> m;
        n--,m--;
        a[n]++;
        a[m]++;
    }
    int ans = 1;
    for(auto &i:a){
        if(i&1) ans = 0;
    }
    cout << (ans?"YES":"NO") << endl;
}