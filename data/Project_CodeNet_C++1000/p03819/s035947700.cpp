#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



int n, m;

int bit[maxn];

void upd(int i, int x) {
    while (i<=m) {
	bit[i]+=x;
	i+=i&-i;
    }
}

int qry(int i) {
    int res=0;
    while (i>0) {
	res+=bit[i];
	i-=i&-i;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n>>m;
    
    vector<pair<int,int>> v;

    for (int i=0; i<n; i++) {
	int l,r; cin>>l>>r;
	v.emplace_back(l,r);
    }


    sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b) {
	    return a.second-a.first < b.second-b.first;
	});


    for (int i=1,j=0; i<=m; i++) {
	
	while (j<n && v[j].second-v[j].first+1 < i) {
	    upd(v[j].first, 1);
	    upd(v[j].second+1, -1);
	    j++;
	}

	int res = n-j;//we will hit the larger intervals for sure
	for (int a=i; a<=m; a+=i) {
	    res += qry(a);
	}
	cout<<res<<"\n";
    }

 

    return 0;
}
