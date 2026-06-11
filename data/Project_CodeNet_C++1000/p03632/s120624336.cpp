#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )
typedef pair<int,int> P;
typedef long long ll;
const int INF = 100000000;

int main() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    cout << max(min(b,d)-max(a,c),0) << endl;
}
