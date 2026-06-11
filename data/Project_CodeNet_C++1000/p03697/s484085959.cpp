#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define sizeOf(A) (sizeof(A))/(sizeof(A[0]))
#define odd(x) ((x) % (2))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    (a+b>=10) ? cout << "error\n" : cout << a + b << "\n";
    return 0;
}
