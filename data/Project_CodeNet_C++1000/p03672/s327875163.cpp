#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include<iomanip>
#include<functional>

using namespace std;
typedef long long ll;

// a と b の最大公約数を返す関数
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main() {
    string s;
    cin >> s;
    int ans = 0;
    for (int i =(int)s.size()- 1; i>0; i--) {
        string S = s.substr(0, i);
        string a = S.substr(0, (int)S. size() / 2);
        string b = S.substr((int)S.size() / 2, a.size());
        if (a == b && (int)S.size()%2==0) {
            ans = (int)S.size();
            break;
        }
    }
    cout << ans << endl;
}
