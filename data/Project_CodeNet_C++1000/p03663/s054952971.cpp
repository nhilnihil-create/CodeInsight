#include <bits/stdc++.h>
using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> P;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int val(vint x) {
    int res = x[0];
    for (int i = 1; i < x.size(); i++) (res *= 10) += x[i];
    return res;
}

signed main() {
    vint ans;
    char a;
    for (int i = 0; i <= 10; i++) ans.push_back(0);
    for (int i = 0; i < 1; i++) {
        cout << "? 10000000000" << endl;
        cin >> a;
        if (a == 'N') break;
        vint cmp;
        for (int j = 0; j < 10; j++) cmp.push_back(1);
        for (int j = 10; j > 0; j--) {
            cout << "? " << val(cmp) << endl;
            cin >> a;
            if (a == 'N') {
                ans[0] = 1;
                ans.resize(j + 1);
                cout << "! " << val(ans) << endl;
                return 0;
            }
            cmp.pop_back();
        }
        cout << "? 2" << endl;
        cin >> a;
        if (a == 'Y')
            cout << "! 1" << endl;
        else
            cout << "! 10" << endl;
        return 0;
    }
    for (int i = 0; i < ans.size() - 1; i++) {
        int lb = 0, ub = 10;
        while (ub - lb > 1) {
            int mid = (lb + ub) / 2;
            ans[i] = mid;
            cout << "? " << val(ans) << endl;
            cin >> a;
            if (a == 'Y') {
                ub = mid;
            } else {
                lb = mid;
            }
        }
        ans[i] = lb;
    }
    for (int i = ans.size() - 2; i >= 0; i--) {
        if (ans[i] == 9)
            ans[i] = 0;
        else {
            ans[i]++;
            break;
        }
    }
    vint cmp;
    cmp.push_back(1);
    for (int i = 1; i < ans.size(); i++) cmp.push_back(0);
    for (int i = ans.size(); i >= 0; i--) {
        cout << "? " << val(cmp) << endl;
        cin >> a;
        if (a == 'Y') {
            ans.resize(i);
            break;
        }
        cmp.pop_back();
    }
    cout << "! " << val(ans) << endl;
    return 0;
}