#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll k; cin >> k;
    cout << 50 << endl;
    vector<ll> a(50);
    for(int i = 0; i < 50; i++) {
        a[i] = i;
        a[i] += k/50LL;
    }
    for(int i = 0; i < k%50LL; i++) {
        a[i] += 50LL;
        for(int j = 0; j <50; j++) {
            if(j==i)continue;
            a[j] -= 1LL;
        }
    }
    for(int i = 0; i < 50; i++) {
        cout << a[i] << " ";
    }
	return 0;
}
