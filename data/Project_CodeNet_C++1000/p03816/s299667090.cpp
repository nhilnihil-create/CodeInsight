#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h> 
#include <set>

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
    int N;
    cin >> N;
    vi A(N);
    set<int> B;
    rep(i, N) {
        cin >> A[i];
        B.insert(A[i]);
    }
    int n = B.size();
    if (n % 2 == 0)cout << n - 1 << endl;
    else cout << n << endl;
}