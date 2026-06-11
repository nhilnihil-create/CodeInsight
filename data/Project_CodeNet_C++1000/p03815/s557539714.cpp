#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include <math.h> 

using namespace std;

#define ll long long int
#define rep(i, n) for(int i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
using vi = vector<int>;
const int MOD = 1e9 + 7;

bool IsPrime(int num){
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) { if (num % i == 0) return false; }
    return true;
}


int main() {
    ll x;
    cin >> x;
    ll a, b;
    a = x / 11;
    b = x % 11;
    if (b == 0) cout << 2 * a << endl;
    else if (b > 0 && b <= 6) cout << 2 * a + 1 << endl;
    else if (b>6) cout << 2 * a + 2 << endl;

}