#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <map>
using namespace std;

#define INF 1e9
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
    int count = 0;
    rep(i, s.size() - 1) {
        if (s.at(i) != s.at(i + 1)) count++;
    }
    cout << count << endl;
}