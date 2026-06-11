#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double PI=acos(-1);
const int INF = numeric_limits<int>::max();

int main(){
    int a, b;
    cin >> a >> b;

    if (a == 1) a = 14;
    if (b == 1) b = 14;

    if (a > b) cout << "Alice" << endl;
    if (a < b) cout << "Bob" << endl;
    if (a == b) cout << "Draw" << endl;


    return 0;
    
}