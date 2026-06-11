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
    string a, b;
    cin >> a >> b;
    if (a.size() > b.size()) goto lasta;
    else if (a.size() < b.size()) goto lastb;
    else {
        rep(i, a.size()) {
            if (a.at(i) < b.at(i)) goto lastb;
            else if (a.at(i) > b.at(i)) goto lasta;
        }
        cout << "EQUAL" << endl;
        return 0;
    }
    lasta:
    cout << "GREATER" << endl;
    return 0;
    lastb:
    cout << "LESS" << endl;
    return 0;
}