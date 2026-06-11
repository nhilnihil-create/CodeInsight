#include<iostream>
#include<map>

using namespace std;
const int MOD = 1e9 + 7;

int N;

long long pow(long long x, int n) {
    long long res = 1;
    while (0 < n) {
        if(n % 2 != 0)
            res = res * x % MOD;
        x = x * x % MOD;
        n /= 2;
    }
    return res;
}

int main() {
    cin >> N;
    int num;
    map<int, int> order;
    for (int i = 0; i < N; i++){
        cin >> num;
        order[num]++;
    }

    for(auto index : order) {
        if( (index.first == 0 && index.second != 1) || ( N % 2 == 0 && index.second != 2)) {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << pow(2, N / 2) << endl;
    return 0;
}