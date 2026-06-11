#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    deque<int> dq;
    int flag = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (flag == 0) {
            dq.push_back(t);
        } else {
            dq.push_front(t);
        }
        flag = 1 - flag;
    }
    if (flag == 0) {
        while (dq.size() > 0) {
            cout << dq.front() << " ";
            dq.pop_front();
        }
    } else {
        while (dq.size() > 0) {
            cout << dq.back() << " ";
            dq.pop_back();
        }
    }
    cout << endl;
}
