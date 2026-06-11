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


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int over = 0;
    int ansmin = 0;
    int ansmax = 0;
    vector<bool> color(8, false);
    rep(i, n) {
        cin >> a.at(i);
        if (a.at(i) < 400) color.at(0) = true;
        else if (a.at(i) < 800) color.at(1) = true;
        else if (a.at(i) < 1200) color.at(2) = true;
        else if (a.at(i) < 1600) color.at(3) = true;
        else if (a.at(i) < 2000) color.at(4) = true;
        else if (a.at(i) < 2400) color.at(5) = true;
        else if (a.at(i) < 2800) color.at(6) = true;
        else if (a.at(i) < 3200) color.at(7) = true;
        else over++;
    }
    rep(i, 8) {
        if(color.at(i)) ansmin++;
    }
    if (ansmin == 0) {
        ansmin = 1;
        cout << ansmin << " ";
    }
    else {
        cout << ansmin << " ";
        ansmax = ansmin;
    }
    if (over > 0) {
        ansmax += over;
    }
    cout << ansmax << endl;
}