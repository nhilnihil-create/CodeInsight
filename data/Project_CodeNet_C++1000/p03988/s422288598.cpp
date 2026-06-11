#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<int> exist(101, 0);
    int emin = N;
    int emax = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        exist[a]++;
        emin = min(emin, a);
        emax = max(emax, a);
    }
    if (exist[emin] >= 3) {
        cout << "Impossible" << endl;
        return 0;
    }
    if (exist[emin] == 2 && emax+1 != emin*2) {
        cout << "Impossible" << endl;
        return 0;
    }
    if (exist[emin] == 1 && emax != emin*2) {
        cout << "Impossible" << endl;
        return 0;
    }
    for (int i = emin+1; i <= emax; i++) {
        if (exist[i] <= 1) {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
    return 0;
}
