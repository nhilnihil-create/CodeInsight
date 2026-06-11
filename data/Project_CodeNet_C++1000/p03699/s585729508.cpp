#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int s, sum = 0;
    vector<int> v;
    for (int i=0; i<n; i++) {
        cin >> s;
        v.push_back(s);
        sum += s;
    }
    sort(v.begin(), v.end());
    if (sum % 10 == 0) {
        auto iter = v.begin();
        while ((*iter) % 10 == 0 && iter != v.end()) {
            iter++;
        } 
        if (iter == v.end()) {
            cout << 0 << endl;
        } else {
            sum -= *iter;
            cout << sum << endl;
        }
    } else {
        cout << sum << endl;
    }
}