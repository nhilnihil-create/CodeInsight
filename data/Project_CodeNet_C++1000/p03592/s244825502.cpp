#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<string>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    for ( int i = 0; i <= n; ++i ) {
        for ( int j = 0; j <= m; ++j ) {
            if ( i * ( m - j ) + j * ( n - i ) == k ) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}