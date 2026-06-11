#include <bits/stdc++.h>
using namespace std;
#define INF 2147483647
#define INFF 9223372036854775807
#define ll long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,m,n) for(int i=m;i<n;i++)
#define ALL(N) (N.begin(),N.end())
#define de cout << "debug" << endl;
#define pb push_back
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll K = 1000000000;

int main() {
    cin.tie(0);    
	ios::sync_with_stdio(false);
    ll N,A,B,C,D;
    cin >> N >> A >> B >> C >> D;
    B -= A;
    A = 0;
    REP(i,N){
        ll Cx = C*i;ll Dx = D*i;
        Cx -= (N - 1 -i) * D;
        Dx -= (N - 1 -i) * C;
        if(Cx <= B && B <= Dx){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}