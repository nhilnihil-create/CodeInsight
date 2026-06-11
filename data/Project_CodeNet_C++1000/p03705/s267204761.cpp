#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll N, A, B;
    cin >> N >> A >> B;
    cout << ((N - 2)*(B - A) + 1)*((N - 2)*(B - A) + 1 >= 0) << endl;
    

    return 0;
}