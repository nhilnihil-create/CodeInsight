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
    string n;
    cin >> n;
    if ( n[0] == n[2] ) cout << "Yes" << endl;
    else                cout << "No" << endl;
    return 0;
}
