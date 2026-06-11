#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )
typedef pair<int,int> P;
typedef long long ll;
const int INF = 100000000;

int main() {
    ll a,b,c;
    cin >> a >> b >> c;
    vector<ll> A(3);
    A[0] = a;
    A[1] = b;
    A[2] = c;
    sort(A.begin(),A.end());
    if (a%2==0 || b%2==0 || c%2==0) {
        cout << 0 << endl;
    }
    else {
        cout << A[0]*A[1]*((A[2]/2+1)-(A[2]/2)) << endl;
    }
}