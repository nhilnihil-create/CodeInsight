#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

const int maxn = 55;

ll k;
ll ans[maxn];

int main() {
    cin >> k;

    int n = 50;
    
    cout << n << endl;

    if(!k) {
	for(int i = 0; i < n; ++i)
	    cout << 0 << " ";
    }
    else {
	for(int i = n; i >= 1; --i)
	    ans[n - i + 1] = i - 1;

	++ans[1];

	if(k == 1) {
	    for(int i = 1; i <= n; ++i)
		cout << ans[i] << " ";

	    return 0;
	}

	 k -= 2;

	for(int i = 1; i <= n; ++i)
	    ans[i] += (k / n);

	k %= n;

	for(int mod = 0; mod <= k; ++mod) {
	    for(int i = 1; i <= n; ++i)
		--ans[i];

	    ans[n - mod] += n + 1;
	}
	
	for(int i = 1; i <= n; ++i)
	    cout << ans[i] << " ";
    }
    
    return 0;
}
