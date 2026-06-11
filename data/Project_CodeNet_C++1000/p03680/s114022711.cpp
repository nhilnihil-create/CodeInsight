#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)
#define FORD(i,a,b) for(int i=int(a); i<int(b); --i)
#define REP(i,N) for(int i=0; i<int(N); ++i)
#define REPD(i,N) for(int i=0; i<int(N); --i)
#define PB push_back
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7
#define MAXR 100000 //配列の最大のrenge

int main() {
    int N; cin>>N;
    vector<int> A(N);
    REP(i,N) cin >> A[i];
    int p = 0;
    REP(i,N) {
        if (A[p] == 2) {
            cout << i+1;
            return 0;
        }
        p = A[p] - 1;
    }
    cout << -1;
}