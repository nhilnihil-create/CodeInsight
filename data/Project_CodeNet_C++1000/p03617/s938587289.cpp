#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cfloat>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <set>
#include <map>
using namespace std;

const double PI=acos(-1);

int main(){
    long q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;
    vector<long> l2 {q*8, h*4, s*2, d};
    vector<long> l1 {q*4, h*2, s};
    sort(l2.begin(), l2.end());
    sort(l1.begin(), l1.end());
    long ll2 = n/2*l2[0], ll1 = n%2*l1[0];
    cout << ll2 + ll1 << endl;
    return 0;
}