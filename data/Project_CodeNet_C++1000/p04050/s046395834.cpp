    #include <bits/stdc++.h>
    using namespace std;
     
    int n, m;
    vector<int> odd, a, b;
     
    int main() {
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int cur;
            cin >> cur;
            if (cur % 2 == 0) {
                a.push_back(cur);
            } else {
                odd.push_back(cur);
            }
        }
     
        if (odd.size() > 2) {
            cout << "Impossible\n";
            return 0;
        }
        if (!odd.empty()) {
            a.insert(a.begin(), odd.back());
            odd.pop_back();
        }
        if (!odd.empty()) {
            a.push_back(odd.back());
            odd.pop_back();
        }
     
        for (int i = 0; i < m; i++) {
            if (i == 0) {
                if (m == 1) {
                    b.push_back(1);
                    if (a[i] - 1 > 0) {
                        b.push_back(a[i] - 1);
                    }
                } else {
                    if (a[i] % 2 == 0) {
                        b.push_back(1);
                        b.push_back(a[i]);
                    } else {
                        b.push_back(a[i] + 1);
                    }
                }
            } else if (i + 1 < m) {
                b.push_back(a[i]);
            } else {
                if (a[i] - 1 > 0) {
                    b.push_back(a[i] - 1);
                }
            }
        }
     
        for (int i = 0; i < m; i++) {
            cout << a[i];
            if (i + 1 < m) {
                cout << ' ';
            }
        }
        cout << '\n' << b.size() << endl;
        for (int i = 0; i < b.size(); i++) {
            cout << b[i];
            if (i + 1 < b.size()) {
                cout << ' ';
            }
        }
        cout << endl;
        return 0;
    }