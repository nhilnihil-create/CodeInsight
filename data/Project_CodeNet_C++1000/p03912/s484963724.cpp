#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

int main(){
    int N ,M;
    cin >> N >> M;
    vector<int> X(N);
    vector<int> R(M);
    vector<int> S(M);
    map<int, int> ma;
    REP(i,N){
        int x;
        cin >> x;
        X[i] = x;
        R[x % M]++;
        ma[x]++;
    }

    for(auto&& p : ma){
        int x = p.first;
        int n = p.second;
        if(n < 2) continue;
        S[x % M] += n/2;
    }

    int ans = 0;
    ans += R[0]/2;
    R[0] -= 2*ans;

    if(M % 2 == 0){
        int tmp;
        tmp = R[M/2]/2;
        R[M/2] -= 2*tmp;
        ans += tmp;
    }

    REPi(x, 1, (M-1)/2+1){
        int tmp;
        tmp = min(R[x], R[M-x]);
        R[x] -= tmp;
        R[M-x] -= tmp;
        ans += tmp;
    }

    //cout << ans << endl;

    REP(x,M){
        if(R[x] >= 2){
            int tmp = 0;
            tmp = min(R[x]/2, S[x]);  
            R[x] -= tmp*2;
            S[x] -= tmp;
            ans += tmp;
        }
    }

    cout << ans << endl;
    return 0;
}
