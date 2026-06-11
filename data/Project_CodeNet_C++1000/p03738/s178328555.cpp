#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <regex>
#include <iomanip>
#include <climits>
using namespace std;
using ll = long long int;
using dd = long double;
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b)
{
    if (a % b == 0)
    {
        return b;
    }
    return gcd(b, a % b);
}

int main()
{
    string A, B;
    cin >> A >> B;

    if (A.size() > B.size()) {
        cout << "GREATER" << endl;
        return 0;
    }
    if (A.size() < B.size()) {
        cout << "LESS" << endl;
        return 0;
    }
    if (A == B){
        cout << "EQUAL" << endl;
        return 0;
    }
    ll cnt = 0;
    while (A[cnt] == B[cnt])
    {
        cnt += 1;
    }
    if (A[cnt] > B[cnt]) {
        cout << "GREATER" << endl;
    } else {
        cout << "LESS" << endl;
    }
}