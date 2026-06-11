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
    ll N;
    cin >> N;
    vector<pair<ll,ll>> A(N);
    for (int i = 0; i < N; ++i) {
        ll tmp;
        cin >> tmp;
        A[i] = make_pair(tmp,i);
    }
    sort(A.begin(),A.end());
    ll count = 0;
    for (int i = 0; i < N; ++i) {
        if(i % 2 == 0 && A[i].second % 2 == 1){
            count++;
        }
    }
    cout << count << endl;
}
