#include<bits/stdc++.h>
using namespace std;

int main() {
    cout.tie(0)->sync_with_stdio(0);
    int A, B; char O;
    cin >> A >> O >> B;
    cout << (O == '+' ? A + B : A - B) << '\n';
}
