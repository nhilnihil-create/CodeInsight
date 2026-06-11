#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

ll COM[1010][1010];
 
void init(){
	rep(i,1010)rep(j,1010) COM[i][j] = 0;
	COM[0][0] = 1;
	repr(i,1,1010){
		COM[i][0] = 1;
		repr(j,1,1010){
			COM[i][j] = COM[i-1][j-1] + COM[i-1][j];
		}
	}
}


int main(){
    init();
    int N,A,B; cin >> N >> A >> B;
    vector<ll> v(N);
    rep(i,N) cin >> v[i];
    sort(v.begin(),v.end(),greater<ll>());
    ll sum = 0;
    bool same = true;
    ll last = 0;
    rep(i,A){
        sum += v[i];
        if(i >= 1){
            if(v[i] != v[i-1] ) same = false;
        }
        last = v[i];
    }
    double average = (double)sum/A;
    cout << fixed << setprecision(7) << average << endl;

    if(!same){
        int cnt1 = 0;
        int cnt2 = 0;
        rep(i,N){
            if(i < A && v[i] == last) cnt1++;
            if(v[i] == last) cnt2++;
        }
        ll ans = COM[cnt2][cnt1];
        cout << ans << endl;
    }
    else{
        int cnt = 0;
        rep(i,N){
            if(v[i] == last) cnt++;
        }
        ll ans = 0;
        repr(i,A,B+1){
            ans += COM[cnt][i];
        }
        cout << ans << endl;
    }

}

