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
    vector<int> num(3);
    rep(i, 3) cin >> num[i];
    sort(num.begin(), num.end());
    cout << num[0] + num[1] << endl;
    return 0;
}
