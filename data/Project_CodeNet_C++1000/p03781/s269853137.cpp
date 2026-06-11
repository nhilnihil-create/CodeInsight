#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
constexpr int MOD = 1000000007;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};

int main() {
    int X;
    cin >> X;
    int i, sum = 0;
    for(i = 1; sum < X; i++) {
        sum += i;
    }
    i--;
    cout << i << endl;
    return 0;
}
