#include "bits/stdc++.h"

using namespace std;

int main() {
    long long n, t, ans = 0, last = 0;
    cin >> n >> t;
    for(long long i = 0; i < n; ++i){
        long long tmp; cin >> tmp;
        if(i == 0)ans += t;
        else if(tmp - last > t)ans += t;
        else ans += (tmp - last);
        last = tmp;
    }
    cout << ans;
	return 0;

}
