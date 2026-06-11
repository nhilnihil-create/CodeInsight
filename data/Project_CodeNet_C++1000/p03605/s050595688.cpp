#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string n;
    cin >> n;
    if(n[0]=='9'||n[1]=='9') cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}