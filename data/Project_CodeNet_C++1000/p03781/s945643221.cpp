#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define INF 120000000

using namespace std;

typedef pair<int, int> P;
typedef long long int LL;

int main() {
    int x;
    cin >> x;
    int sum = 0, i;
    for (i = 1; sum < x; i++) sum += i;
    cout << i - 1 << endl;
    return 0;
}
