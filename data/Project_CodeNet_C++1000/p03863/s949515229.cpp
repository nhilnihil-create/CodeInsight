#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;

    if( (s.size()%2 == 0)^(s.front() == s.back()) ) {
        cout << "Second";
    }
    else {
        cout << "First";
    }

    cout << endl;
    return 0;
}