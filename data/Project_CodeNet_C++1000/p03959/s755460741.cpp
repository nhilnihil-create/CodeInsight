#include<algorithm>
#include<complex>
#include<ctype.h>
#include<iomanip>
#include<iostream>
#include<fstream>
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
#define p_yes() p("Yes")
#define p_no() p("No")

const ll mod = 1e9 + 7;
const ll inf = 1e18;

template < typename T >
void vprint(T &V){
	for(auto v : V){
    	cout << v << " ";
	}
	cout << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N;
    cin >> N;

    vector<ll> A(N);
    FOR(i, 0, N){
        cin >> A.at(i);
    }

    vector<ll> B(N);
    FOR(i, 0, N){
        cin >> B.at(i);
    }

    // 高さ確定の部分にはその値を入れる
    // 未確定部分には「h以下」という情報として -h を入れる
    vector<ll> C(N);
    ll height = 0;
    FOR(i, 0, N){
        if(height!=A[i]){
            C[i] = A[i];
        }else{
            C[i] = -height;
        }
        height = A[i];
    }

    // 逆方向から
    vector<ll> D(N);
    height = 0;
    for(int i=N-1; i>=0; i--){
        if(height!=B[i]){
            D[i] = B[i];
        }else{
            D[i] = -height;
        }
        height = B[i];
    }

    // マージ
    vector<ll> E(N);
    FOR(i, 0, N){
        if(C[i]<0 && D[i]>0){
            if(-C[i] < D[i]){
                p(0);
                return 0;
            }
            E[i] = D[i];
        }
        else if(D[i]<0 && C[i]>0){
            if(-D[i] < C[i]){
                p(0);
                return 0;
            }
            E[i] = C[i];
        }
        else if(C[i]<0 && D[i]<0){
            E[i] = max(C[i], D[i]);
        }
        // 以降は正
        else if(C[i]>0 && D[i]>0 && C[i]!=D[i]){
            // 矛盾
            p(0);
            return 0;
        }
        else if(C[i]>0 && D[i]>0 && C[i]==D[i]){
            E[i] = C[i];
        }
        else{
            //p("考慮漏れ");
        }
    }

    ll answer = 1;
    height = E[0];
    FOR(i, 1, N-1){
        if(E[i]<0){
            answer *= -E[i];
            answer %= mod;
        }
    }

    p(answer);

    return 0;
}