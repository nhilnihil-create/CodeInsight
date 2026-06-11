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
    ll N;
    cin >> N;

    if(N==1){
        p(1);
        return 0;
    }

    ll left = 1; // 不可能
    ll right = N; // 可能

    while(left+1!=right){
        ll center = (left + right) / 2;
        ll sum = center * (center+1) / 2;
        if(sum >= N){
            right = center;
        }else{
            left = center;
        }
    }

    while(N!=0){
        for(int i=right; i>=1; i--){
            if(N>=i){
                N -= i;
                p(i);
            }
        }
    }

    return 0;
}