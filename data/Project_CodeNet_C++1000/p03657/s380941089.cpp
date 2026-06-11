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
    int a, b;
    cin >> a >> b;
    if ( a % 3 == 0 || b % 3 == 0 || ( a + b ) % 3 == 0 ) cout << "Possible" << endl;
    else                                                  cout  <<"Impossible" << endl; 
    return 0;
}
