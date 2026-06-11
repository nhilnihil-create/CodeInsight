#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll inf = 10000000;

int main() {
    int N;
    cin >> N;
    vector<int>a(N);
    ll total = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        total += a[i];
    }
    int x = total/N; 
    int y = ceil((double)total/(double)N);
    int c1 = 0;
    int c2 = 0;
    for (int i = 0; i < N; i++) {
        c1 += pow((a[i]-x), 2);
        c2 += pow((a[i]-y), 2);
    }
    cout << min(c1, c2) << endl;
}
