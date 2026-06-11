#include<algorithm>
#include<complex>
#include<ctype.h>
#include<iomanip>
#include<iostream>
#include<map>
#include<math.h>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<stdio.h>
#include<string>
#include<string>
#include<vector>

using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << endl
#define p_yes() p("YES")
#define p_no() p("NO")

template < typename T >
void vprint(T &V){
	for(auto v : V){
    	cout << v << " ";
	}
	cout << endl;
}

const ll mod = 1e9 + 7;
const ll inf = 1e18;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N, K;
    cin >> N >> K;

    vector<ll> A(N);
    FOR(i, 0, N){
        cin >> A.at(i);
    }

    // 累積和
    vector<ll> Ac(N);
    Ac[0] = A[0];
    FOR(i, 1, N){
        Ac[i] = Ac[i-1] + A[i];
    }
    
    // 累積和
    vector<ll> B(N);
    FOR(i, 0, N){
        B[i] = max(A[i], 0LL);
    }
    FOR(i, 1, N){
        B[i] += B[i-1];
    }

    ll max_score = 0;

    // Kをiからi+K-1まで置く
    FOR(i, 0, N-K+1){        
        FOR(j, 0, 2){
            ll score = 0;

            // Kの範囲を黒
            if(j==0){
                if(i==0){
                    score += Ac[K-1];
                }
                else{
                    score += Ac[i+K-1] - Ac[i-1];
                }
            }
            // Kの範囲を白
            else{
                score = 0;
            }

            // 自由箇所
            if(i==0){
                // 右の自由
                score += B[N-1] - B[K-1];
            }else{
                // 右の自由
                score += B[N-1] - B[i+K-1];
                // 左の自由
                score += B[i-1];
            }

            // 得点が出た
            max_score = max(max_score, score);
        }
    }

    p(max_score);

    return 0;
}