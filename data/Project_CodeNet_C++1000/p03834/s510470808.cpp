#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

#define INF 1e9
#define LLINF 1e18
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return(gcd(b, a % b));
    }
}


int main() {
    string s;
    cin >> s;
    string a, b, c;
    rep(i, s.size()) {
        if (i < 5) a.push_back(s.at(i));
        else if (i > 5 && i < 13) b.push_back(s.at(i));
        else if (i > 13 && i < s.size()) c.push_back(s.at(i));
    }
    cout << a << " " << b << " " << c << endl;
}