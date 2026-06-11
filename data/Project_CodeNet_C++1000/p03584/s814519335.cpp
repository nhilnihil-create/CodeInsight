#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

typedef unsigned int uint;

int main(){
    uint N, K;
    cin >> N >> K;
    vector<uint> A(N);
    vector<uint> B(N);
    REP(i,N){
        uint a, b;
        cin >> a >> b;
        A[i] = a;
        B[i] = b;
    }

    int last = -1;
    vector<uint> answers;
    answers.push_back(K);
    for(int b = 0; b <= 30; b++){
        int bit = (K >> b) & 1;
        if(bit == 1 && last == 0){
            //uint tmp = K;
            //tmp &= ~(1U << b);
            K &= ~(1U << b);
            uint tmp = K;
            for(int x = 0; x < b; x++){
                tmp |= (1U << x);
            }
            answers.push_back(tmp);
            last = 0;
        }
        else
            last = bit;
    }

    ll ans = 0;
    for(auto&& x : answers){
        //for(int b = 30; b >= 0; b--){
        //    cout << ((x >> b) & 1);
        //}
        //cout << endl;

        ll tmp = 0;
        REP(i,N){
            uint a = A[i];
            bool add = true;
            for(int b = 0; b <= 30; b++){
                int bitx = (x >> b) & 1;
                int bita = (a >> b) & 1;
                if(bitx == 0 && bita == 1){
                    add = false;
                    break;
                }
            }
            if(add){
                tmp += B[i];
            }
        }

        chmax(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}
