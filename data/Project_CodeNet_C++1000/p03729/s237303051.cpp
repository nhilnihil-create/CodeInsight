#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
using P = pair <int, int>;

ll mod = 1000000007;
ll ans = 1<<29;

int main() {
    string a,b,c;
    cin >> a >>b >>c;
    if(a[a.size()-1]==b[0]&&b[b.size()-1]==c[0])cout<< "YES" <<endl;
    else cout<<"NO"<<endl;
}