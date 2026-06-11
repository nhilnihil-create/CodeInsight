#include <bits/stdc++.h>
#define MAXN 200010
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define in_range(x, y, n) (x >= 0 and x<n and y >=0 and y<n)
using namespace std;
const ll mod = 1e18 + 7;


int main (){
    ios_base::sync_with_stdio(false);
    set <int> s;
    int a, b, c;
    cin >> a >> b >> c;
    s.insert(a);
    s.insert(b);
    s.insert(c);

    cout << s.size() << endl;
    return 0;
}