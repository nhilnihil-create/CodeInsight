#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<ll> A(N);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    sort(A.begin(), A.end(), greater<int>());
    ll output = 1;
    sum -= A[0];
    for (int i = 1; i < N; i++) {
        if (sum * 2 >= A[i - 1])
            output++;
        else
            break;
        sum -= A[i];
    }
    cout << output << endl;

    return 0;
}
