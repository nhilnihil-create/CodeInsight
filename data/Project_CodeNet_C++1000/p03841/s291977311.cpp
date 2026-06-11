#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define     endl               '\n'
#define     fast_io            ios::sync_with_stdio(false); cin.tie(0);
#define     all(x)             begin(x), end(x)
#define     debug(x)           cerr <<"Line "<< __LINE__ <<" : "<< #x " = "<< x <<endl;
 
template<typename T, typename TT>
ostream& operator<<(ostream &os, const pair<T, TT> &t) { return os<<"("<<t.first<<", "<<t.second<<")"; }
template<typename T>
ostream& operator<<(ostream& os, const vector<T> &t) { for(auto& i: t) os<<i<<" "; return os; }





int main(int argc, char** argv) {
    //fast_io
    
    int n;
    cin >> n;
    
    vector<int> x(n+1);
    for(int i = 1; i <= n; ++i) cin >> x[i];
    vector<pii> sorted_x;
    for(int i = 0; i < n; ++i) sorted_x.emplace_back(x[i+1], i+1);
    sort(all(sorted_x));
    //cout << sorted_x << endl;
    
    vector<int> a(n*n + 1);

    for(const auto& item : sorted_x) {
	int i = item.second;
	a[x[i]] = i; // i th occurance of i in x[i]
	int slot = 1;
	for(int j = 1; j < i; ++j) { // [1, i) occurances of i
	    while(slot < x[i] && a[slot]) ++slot;
	    if(slot < x[i]) {
		a[slot] = i;
	    } else {
		cout << "No" << endl;
		exit(0);
	    }
	}
    }
    
    for(int ii = n-1; ii >= 0; --ii) {
	int i = sorted_x[ii].second;
	int slot = n*n;
	for(int j = i + 1; j <= n; ++j) {
	    while(slot > x[i] && a[slot]) --slot;
	    if(slot > x[i]) {
		a[slot] = i;
	    } else {
		cout << "No" << endl;
		exit(0);
	    }
	}
    }
    
    cout << "Yes" << endl;
    for(int i = 1; i <= n * n; ++i) cout << a[i] << " ";
    cout << endl;
    
    
    return 0;
}
