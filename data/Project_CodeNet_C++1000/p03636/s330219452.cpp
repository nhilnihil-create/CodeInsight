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


int main() {
    string a;
    cin >> a;
    cout << a.at(0) << a.size() - 2 << a.at(a.size() - 1) << endl;
}