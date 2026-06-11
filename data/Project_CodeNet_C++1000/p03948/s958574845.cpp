#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



int n,t;
int a[maxn];
map<int,int> ai;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n>>t;
    for (int i=0; i<n; i++) {
	cin>>a[i];
    }

    int buy=1e9;
    int mx=0;
    for (int i=0; i<n; i++) {
	if (a[i]-buy>mx) {
	    mx=a[i]-buy;
	}
	buy=min(buy,a[i]);
    }


    int ans=0;
    for (int i=0; i<n; i++) {
	if (ai.count(a[i]-mx)) {
	    ans++;
	}
	ai[a[i]]=i;
    }

    cout<<ans<<endl;

    return 0;
}
