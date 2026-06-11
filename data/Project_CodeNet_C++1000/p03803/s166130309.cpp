#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int INF = 1<<29;
//const int MODINF = 1000000007;
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;
    if (A == 1) A = 14;
    if (B == 1) B = 14;
    if (A > B) cout << "Alice" << endl;
    else if(A == B) cout << "Draw" << endl;
    else cout << "Bob" << endl;
}