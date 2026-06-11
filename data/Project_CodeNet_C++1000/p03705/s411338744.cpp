#include <bits/stdc++.h>
using namespace std;

int main()
{
    int64_t N, A, B;
    cin >> N >> A >> B;
    cout << max((int64_t)0, (A + B * (N - 1)) - (A * (N - 1) + B) + 1) << endl;
}
