#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
const int INF = 1<<29;
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << a + b + c - max(a, max(b,c)) << endl;
}
