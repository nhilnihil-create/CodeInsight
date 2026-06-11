#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n;i++)

int main()
{
    int A, B;
    cin >> A >> B;
    cout << ((A * B * (A + B)) % 3 == 0 ? "Possible" : "Impossible") << endl;
}