#include<bits/stdc++.h>
#define rep(i, n) for(int i=0;i<(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define repa(i, n) for(int i=1;i<(n);++i)
#define foreach(i, n) for(auto &i:(n))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define all(x) (x).begin(), (x).end()
#define bit(x) (1ll << (x))
using namespace std;
using ll = long long;
const ll MOD = (ll)1e9+7;
//const ll MOD = 998244353;
//const ll MOD = 924844033;
const int INF = (ll)1e9+7;
const ll INFLL = (ll)1e18;
const double EPS = 1e-5;
using namespace std;
template<class t>
using vvector = vector<vector<t>>;
template<class t>
using vvvector = vector<vector<vector<t>>>;
template<class t>
using priority_queuer = priority_queue<t, vector<t>, greater<t>>;
template<class t, class u> bool chmax(t &a, u b){if(a<b){a=b;return true;}return false;}
template<class t, class u> bool chmin(t &a, u b){if(a>b){a=b;return true;}return false;}

#ifdef DEBUG
#define OUTPUT(x) (output(x), outendl())
#else
#define OUTPUT(x) (void)0
#endif

ll modpow(ll x, ll b){
	ll res = 1;
	while(b){
		if(b&1)res = res * x % MOD;
		x = x * x % MOD;
		b>>=1;
	}
	return res;
}

ll modinv(ll x){
	return modpow(x, MOD-2);
}

bool was_output = false;
template<class t>
void output(t a){
	if(was_output)cout << " ";
	cout << a;
	was_output = true;
}
void outendl(){
	was_output = false;
	cout << endl;
}

int n;
int m;
vector<pii> colors;
vvector<int> edges;

void dye(int place,int distance,int color){
    if(distance<0)return;
    if(colors[place].first>0&&colors[place].second>=distance){
        return;
    }
    if(colors[place].first==0){
        colors[place].first = color;
    }
    colors[place].second = distance;
    foreach(i,edges[place]){
        dye(i,distance-1,color);
    }
}

int main(){
    cin >> n >> m;
    colors.resize(n,pii(0,0));
    edges.resize(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        --a;
        --b;
        edges[a].push_back(b);
        edges[b].push_back(a);

    }
    int q;
    cin >> q;
    vvector<int> line(q);
    foreach(i,line){
        vector<int> d(3);
        foreach(j,d){
            cin >> j;
        }
        --d[0];
        i = d;
    }
    reverse(all(line));
    foreach(i,line){
        dye(i[0],i[1],i[2]);
    }
    foreach(i,colors){
        cout << i.first << endl;
    }


	return 0;
}
