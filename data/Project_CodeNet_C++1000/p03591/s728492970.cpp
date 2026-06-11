#include<bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define pb push_back
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair< int, int > P;
typedef pair< LL, LL > LP;
typedef pair< int, P > iP;
typedef pair< P, P > PP;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1000000007;

int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    if( s.size() < 4 ) cout << "No";
    else {
        if( s[0] == 'Y' && s[1] == 'A' && s[2] == 'K' && s[3] == 'I' ) 
            cout << "Yes";
        else cout << "No";
    }
    cout << endl;
    return 0;
}
