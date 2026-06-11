#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define PI acos(-1)

int main() {
    int N;
    cin >> N;
    int div4 = 0, div2 = 0;
    Rep(i, N) {
        int a;
        cin >> a;
        if (a % 4 == 0) div4++;
        else if (a % 2 == 0) div2++;
    }
    if (div4 >= N / 2) puts("Yes");
    else if (div2 >= N - div4 * 2) puts("Yes");
    else puts("No");
    return 0;
}