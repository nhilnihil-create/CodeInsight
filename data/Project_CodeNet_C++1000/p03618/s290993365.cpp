#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
using ll = long long;
using graph = std::vector<std::vector<ll>>;

using namespace std;

int main() {
    string A;
    cin >> A;
    vector<ll> bucket(30);
    for(int i = 0; i < 30; i++){
        bucket[i] = 0;
    }
    for(ll i = 0; i < A.size();i++){
        bucket[A[i] - 'a']++;
    }
    ll count = 0;
    for(int l = 0; l < 29; l++){
        for(int r = l + 1; r < 30; r++){
            count += bucket[l] * bucket[r];
        }
    }
    cout << count + 1ll << endl;
}
