#include "bits/stdc++.h"
using namespace std;
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define PI acos(-1)
typedef long long ll;

int main() {
    string S;
    cin >> S;
    Reverse(S);
    while (true) {
        if (S.substr(0, 5) == "maerd") S = S.substr(5);
        else if (S.substr(0, 7) == "remaerd") S = S.substr(7);
        else if (S.substr(0, 5) == "esare") S = S.substr(5);
        else if (S.substr(0, 6) == "resare") S = S.substr(6);
        else break;
    }
    cout << (S.size() == 0 ? "YES" : "NO") << endl;
    return 0;
}