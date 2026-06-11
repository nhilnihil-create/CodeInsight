#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

int A[400][400];
int main(){
    int N, M;
    cin >> N >> M;
    REP(i,N){
        REP(j,M){
            int a;
            cin >> a;
            a--;
            A[i][j] = a;
        }
    }

    int ans = 1e5;
    set<int> se;
    REP(i,M) se.insert(i);

    REP(i,M){
        map<int, int> ma;
        REP(n,N){
            REP(m,M){
                int a = A[n][m];
                if(se.find(a) != se.end()){
                    ma[a]++;
                    break;
                }
            }
        }

        int maxidx;
        int tmp = 0;
        for(auto&& p : ma){
            if(tmp < p.second){
                tmp = p.second;
                maxidx = p.first;
            }
        }
        chmin(ans, tmp);
        se.erase(maxidx);
    }

    cout << ans << endl;
    return 0;
}
