#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#include <vector>
#include <numeric>
#include <map>
#include <cmath>
#include <iomanip>
#include <queue>
using ll =long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vs = vector<string>;

int main() {
    ll A, B, C;
    cin >> A >> B >> C;


    ll mini = min(min(abs(A*B*(C/2) - A*B*(C-C/2)), abs(A*C*(B /2) - A*C*(B-B/2))), abs(B*C*(A /2) - B*C*(A-A/2)));

    cout << mini << endl;
}