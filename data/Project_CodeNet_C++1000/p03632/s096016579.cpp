#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long int;
int main()
{
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << max(0LL, min(B,D) - max(A, C)) << endl;
}