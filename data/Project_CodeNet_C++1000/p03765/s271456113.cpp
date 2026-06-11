#include <bits/stdc++.h>
using namespace std;
int psum[100005];
int psum2[100005];
int main(){
	string a, b; cin >> a >> b;
  	for (int i = 1; i <= a.length(); i++){
        psum[i] = psum[i - 1] + (a[i - 1] == 'A' ? 1 : -1);
    }
    for (int i = 1; i <= b.length(); i++){
        psum2[i] = psum2[i - 1] + (b[i - 1] == 'A' ? 1 : -1);
    }
    int q; cin >> q;
    while (q--){
        int a, b, c, d; cin >> a >> b >> c >> d;
        if (((psum[b] - psum[a - 1]) - (psum2[d] - psum2[c - 1])) % 3 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}