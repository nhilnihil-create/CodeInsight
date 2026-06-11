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


int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> line(n);
    map<int,map<int,int>> cnt;
    foreach(i,line){
        cin >> i;
        ++cnt[i%m][i];
    }
    int ans = 0;
    repa(i,m/2+1){
        if(i*2==m)continue;
        deque<int> l;
        deque<int> r;
        foreach(j,cnt[i]){
            if(j.second&1){
                l.push_front(j.second);
            }else{
                l.push_back(j.second);
            }
        }
        foreach(j,cnt[m-i]){
            if(j.second&1){
                r.push_front(j.second);
            }else{
                r.push_back(j.second);
            }
        }
        while(l.size()&&r.size()){
            int a = l.front();
            l.pop_front();
            int b = r.front();
            r.pop_front();
            ++ans;
            --a;
            --b;
            if(a){
                if(a&1){
                    l.push_front(a);
                }else{
                    l.push_back(a);
                }
            }
            if(b){
                if(b&1){
                    r.push_front(b);
                }else{
                    r.push_back(b);
                }
            }
        }
        while(l.size()){
            ans += l.front() / 2;
            l.pop_front();
        }
        while(r.size()){
            ans += r.front() / 2;
            r.pop_front();
        }
    }
    {
        int sum = 0;
        foreach(i,cnt[0]){
            sum += i.second;
        }
        ans += sum / 2;
    }
    if(~m&1){
        int d = m / 2;
        int sum = 0;
        foreach(i,cnt[d]){
            sum += i.second;
        }
        ans += sum / 2;
    }
    cout << ans << endl;
}
