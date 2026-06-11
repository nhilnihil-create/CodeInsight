#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<int,int>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll pow(ll a, ll n, ll m) {
	ll ret = 1LL;
	for (; n > 0LL; n >>= 1LL, a = a * a % m) {
		if (n % 2LL == 1LL) {
			ret = ret * a % m;
		}
	}
	return ret;
}

int main(){
    int N;
    cin>>N;
    vector<int> v(N,0);
    rep(i,N){
        int x;
        cin>>x;
        v[x]++;
    }
    bool can = true;
    if(N%2==0){
        for(int i = N-1; i >= 0; i-=2){
            if(v[i]!=2) can = false;
        }
        if(!can) cout<<0<<endl;
        else cout<<pow(2LL,N/2,mod)<<endl;
    } 
    else{
        for(int i = N-1; i>=0; i-=2){
            if(i!=0){
                if(v[i]!=2) can = false;
            }
            else if(v[i]!=1) can = false;
        }
        if(!can) cout<<0<<endl;
        else cout<<pow(2LL,N/2,mod)<<endl;
    }
} 