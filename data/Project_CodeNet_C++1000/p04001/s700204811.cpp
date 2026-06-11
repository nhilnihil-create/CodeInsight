#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep01(i, n) for(int i = 0; i < (n) + 1; i++)
#define rep10(i, n) for(int i = 1; i < (n); i++)
#define all(a) (a).begin(), (a).end()
typedef long long int ll;
using namespace std;

//ARC061A
int main()
{
    string s;
    cin >> s;

    ll totalsum = 0;
    for (ll bn = 0; bn < (1 << s.length() - 1); bn++) {
        ll sum = 0;
        string se = "";
        se += s[0];
        rep10(bit, s.length()) {
            if (bn & 1 << (bit - 1)) {
                sum += stoll(se);
                se = "";
            }
            se += s[bit];
        }
        sum += stoll(se);
        totalsum += sum;
    }
    
    cout << totalsum << endl;

    return 0;
}