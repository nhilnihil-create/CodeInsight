#include <bits/stdc++.h>
using namespace std;
void chmax(int& a, int b) { if (a < b) a = b; }

int main() {
    int n;
    cin >> n;
    vector<int> id(n), a(n), b(n);
    for (int& e : id) { cin >> e; e--; }
    for (int i = 0; i < n; i++) {
        a[i] = b[n-1-i] = (n+1) * (i+1);
    }
    
    int nin = 0;
    for (const int& i : id) {
        int d = max(0, nin+1 - (a[i] + b[i]));
        int pa = d/2, pb = d - pa;
        a[i] += pa; b[i] += pb;
        nin = a[i] + b[i];
    }
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i+1 == n ? '\n' : ' ');
    }
    for (int i = 0; i < n; i++) {
        cout << b[i] << (i+1 == n ? '\n' : ' ');
    }
    return 0;
}