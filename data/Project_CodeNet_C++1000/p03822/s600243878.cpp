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

vector<vector<ll> > A;

ll dfs(ll a){
    if(A[a].size()==0){
        return 0;
    }

    vector<ll> D;
    for(ll child : A[a]){
        ll d = dfs(child);
        D.push_back(d);
    }
    sort(ALL(D), greater<ll>());

    ll max_depth = 0;
    FOR(i, 0, D.size()){
        ll d = D[i] + (i+1);
        max_depth = max(max_depth, d);
    }

    return max_depth;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N;
    cin >> N;

    A.resize(N+1);

    FOR(i, 2, N+1){
        ll winner;
        cin >> winner;

        A[winner].push_back(i);
    }

    ll answer = dfs(1);
    p(answer);
    
    return 0;
}