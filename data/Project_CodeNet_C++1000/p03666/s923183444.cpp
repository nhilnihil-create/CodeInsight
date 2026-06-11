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
#define p_yes() p("YES")
#define p_no() p("NO")

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
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    if(A>B){
        swap(A, B);
    }
    B -= A;

    FOR(plus, 0, N){
        ll minus = N-1-plus;
        
        ll right = D * plus - C * minus;
        ll left  = C * plus - D * minus;
        
        if(left<=B && B<=right){
            p_yes();
            return 0;
        }
    }   

    p_no();
    return 0;
}