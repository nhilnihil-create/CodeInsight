#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;
#define REP(i,n) for (int i = 0; i < n; i++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;

int main ()
{
    int N; cin >> N;
    int ans = 0;
    int min_d = 1e9 + 1;
    REP(i,N) {
        int A,B;
        cin >> A >> B;
        if (min_d > B) {
            min_d = B;
            ans = A + B;
        }
    }

    cout << ans << endl;
    return 0;
}
