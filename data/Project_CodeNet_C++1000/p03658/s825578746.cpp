#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;

int main () {
    int n,k;
    vector <int> a;
    cin >> n >> k;
    for (int i=0;i<n;i++) {
        int m;
        cin >> m;
        a.push_back(m);
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int sum=0;
    for (int i=0;i<k;i++) {
        sum+=a[i];
    }
    cout << sum << endl;
    return 0;
}