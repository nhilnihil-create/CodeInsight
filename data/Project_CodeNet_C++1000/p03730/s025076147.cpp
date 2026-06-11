#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int gcd(int a, int b) {
    if (b==0) {
        return a;
    }
    return gcd(b,a%b);
}

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int d = gcd(a,b);
    if (c%d==0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
