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
    int x, y;
    cin >> x >> y;
    vector<int> a{1,3,1,2,1,2,1,1,2,1,2,1};
    if (a.at(x - 1) == a.at(y - 1)) cout << "Yes" << endl;
    else cout << "No" << endl;
}