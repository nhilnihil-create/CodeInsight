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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
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

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

const ll mod = 1e9 + 7;
const ll inf = 1e18;

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

    ll sum = 0;
    for(ll a : A){
        sum += a;
    }

    ll one_time = (N+1)*N/2;
    if(sum % one_time != 0){
        p_no();
        return 0;
    }
    else{
        vector<ll> B(N);
        FOR(i, 0, N-1){
            B[i] = A[i+1] - A[i];
        }
        B[N-1] = A[0] - A[N-1];

        ll k = sum / one_time;
        
        FOR(i, 0, N){
            B[i] -= k;
        }
        
        // check
        FOR(i, 0, N){
            if(B[i] <= 0 && B[i]%N==0){

            }else{
                p_no();
                return 0;
            }
        }
    }

    p_yes();
    
    return 0;
}