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
#include <numeric>
using namespace std;
int main() {
    int a,b,c,m,res;
    vector<int> ans;
    for (int i=0;i<3;i++) {
        cin >> m;
        ans.push_back(m);
    }
    sort(ans.begin(),ans.end());
    ans.pop_back();
    res=accumulate(ans.begin(),ans.end(),0);
    cout << res << endl;
    return 0;
}