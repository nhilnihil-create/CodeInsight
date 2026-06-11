#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;


int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int preA = -1, preB = -1, preC = -1;
    int nextA, nextB, nextC;

    int count = 0;
    while (A%2 == 0 && B%2 == 0 && C%2==0) {
        if (A == preA && B == preB && C == preC) {
            count = -1;
            break;
        }
        preA = A;
        preB = B;
        preC = C;

        nextA = B / 2 + C / 2;
        nextB = C / 2 + A / 2;
        nextC = A / 2 + B / 2;
        A = nextA;
        B = nextB;
        C = nextC;
        count++;
    }

    cout << count << endl;

    return 0;
}