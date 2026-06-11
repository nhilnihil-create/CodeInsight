#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    ll N, num = 0, count = 0;
    cin >> N;

    count += (N / 11) * 2;
    if(N % 11 > 6) count += 2;
    else if(N % 11 > 0) count++;

    cout << count << endl;
}