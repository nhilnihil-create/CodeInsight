#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;

    cin >> n;
    int tempCost = 0;
    int minCost = 999999999;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    
    sort(a.begin(), a.end());

    // 最小値から最大値までを範囲として計算する


    for (int i = a.at(0); i <= a.at(a.size() - 1); i++) {
        tempCost = 0;
        for (int j = 0; j < a.size(); j++) {
            tempCost  += (i - a.at(j)) * (i - a.at(j));
        }
     
        if (tempCost < minCost) {
            minCost = tempCost;
        } 
    }

    cout << minCost << endl;
}
