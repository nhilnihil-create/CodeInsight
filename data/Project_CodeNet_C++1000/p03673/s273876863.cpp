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
    deque<int> num;
    int mod = N % 2;
    for (int i = 1; i <= N;i++) {
        int a;
        cin >> a;
        if (i % 2 == mod) num.push_front(a);
        else num.push_back(a);
    }
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << num.front();
        num.pop_front();
    }
    return 0;
}