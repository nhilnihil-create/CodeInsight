#include <bits/stdc++.h>
using namespace std;

int n,m,sum;
int a[110];
vector<int> v, ansa, ansb;
int main() {
    cin >> n >> m;
    int odd = 0;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        if (a[i] & 1) {
            v.push_back(a[i]);
        }
    }
    if (v.size() > 2) {
        cout << "Impossible" << endl;
        return 0;
    }
    if (v.size() >= 1) ansa.push_back(v[0]);
    for (int i = 0; i < m; i++) {
        if (!(a[i] & 1)) ansa.push_back(a[i]);
    }
    if (v.size() == 2) ansa.push_back(v[1]);
    
    if (ansa[0] - 1 > 0) ansb.push_back(ansa[0] - 1);
    sum += ansa[0] - 1;
    for (int i = 1; i < ansa.size(); i++) {
        ansb.push_back(ansa[i] + (i == (int)ansa.size() - 1));
        sum += ansb[ansb.size() - 1];
    }
    if (sum != n) ansb.push_back(1);
    for (int i = 0; i < ansa.size(); i++) {
        cout << ansa[i] << " \n"[i == ansa.size() - 1];
    }
    cout << ansb.size() << endl;
    for (int i = 0; i < ansb.size(); i++) {
        cout << ansb[i] << " \n"[i == ansb.size() - 1];
    }
    return 0;
}