#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if ( b - a == c - b ) cout << "YES" << endl;
    else                  cout << "NO" << endl;
    return 0;
}
