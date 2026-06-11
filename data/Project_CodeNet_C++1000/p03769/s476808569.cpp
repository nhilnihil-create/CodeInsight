#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

#define remove_duplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())));

typedef long long longint;



longint n;
deque<int> q;
int main(){
    #define file "in"
    //freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);

    cin >> n;
    vector<int> op;
    while (n) { if (n % 2 == 1) op.push_back(0), n /= 2; else op.push_back(1), n--; }
    deque<int> q;
    int value = 1;
    for (int i = op.size() - 1; i >= 0; i--) {
        if (op[i] == 1) q.push_front(value);
        else q.push_back(value);
        value++;
    }
    cout << q.size() * 2 << endl;
    for (int value = 1; value <= q.size(); value++) cout << value << " ";
    for (int value : q) cout << value << " ";
    return 0;
}
