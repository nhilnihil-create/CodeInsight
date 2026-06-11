#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;

ll mod = 1000000007;
ll ans = 1<<29;

int main() {
    int a,b,c;
    cin >>a >>b >>c;

    if(c>=a&& c<=b) cout << "Yes" <<endl;
    else cout << "No" << endl;
}