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
ll MOD = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    string s;
    cin >> s;
    cout << s.substr(0, 4) << " " << s.substr(4, 8) << endl;
    return 0;
}
