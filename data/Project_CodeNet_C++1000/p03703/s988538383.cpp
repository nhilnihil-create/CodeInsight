#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;


int N;
int bit[maxn];
void inc(int i) {
    while (i<=N) {
	bit[i]++;
	i+=i&-i;
    }
}
int get(int i) {
    int res=0;
    while (i) {
	res+=bit[i];
	i-=i&-i;
    }
    return res;
}

int n;
ll k;
ll a[maxn];

ll ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n>>k;
    for (int i=0; i<n; i++) {
	cin>>a[i];
	a[i]-=k;
    }
    vector<ll> pref={0};
    for (int i=0; i<n; i++) {
	pref.push_back(pref.back()+a[i]);
    }

    pref.push_back(-2e18);
    sort(pref.begin(),pref.end());
    pref.erase(unique(pref.begin(),pref.end()),pref.end());
    N=pref.size();

    inc(lower_bound(pref.begin(),pref.end(),0)-pref.begin());
    ll acc=0;
    for (int i=0; i<n; i++) {
	acc+=a[i];
	int id=lower_bound(pref.begin(),pref.end(),acc)-pref.begin();
	ans += get(id);
	inc(id);
	//watch(ans);
    }
    cout<<ans<<endl;
  

    return 0;
}
