#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const int INF = 1001001001;
const int MOD = 1000000007;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b == c || a + c == b || b + c == a) {
        puts("Yes");
    } else {
        puts("No");
    }
}