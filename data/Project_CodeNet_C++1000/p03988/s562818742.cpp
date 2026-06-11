#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    multiset<int> ds;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        ds.insert(d);
    }
    int d = *max_element(ds.begin(), ds.end());
    if (d % 2 == 0) {
        int D = d;
        while (D > d / 2) {
            if (ds.count(D) < 2) {
                cout << "Impossible" << endl;
                return 0;
            }
            ds.erase(ds.find(D));
            ds.erase(ds.find(D));
            D--;
        }
        if (ds.count(D) < 1) {
            cout << "Impossible" << endl;
            return 0;
        }
        ds.erase(ds.find(D));
        for (int a : ds) {
            if (a <= D) {
                cout << "Impossible" << endl;
                return 0;
            }
        }

        cout << "Possible" << endl;
        return 0; 
    }

    int D = d;
    while (D > d / 2) {
        if (ds.count(D) < 2) {
            cout << "Impossible" << endl;
            return 0;
        }
        ds.erase(ds.find(D));
        ds.erase(ds.find(D));
        D--;
    }
    for (int a : ds) {
        if (a <= D + 1) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    cout << "Possible" << endl;
}