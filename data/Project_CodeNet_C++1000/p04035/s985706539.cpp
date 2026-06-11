#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, l;
    cin >> n >> l;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool ok = false;
    int id = -1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] + a[i + 1] >= l) {
            ok = true;
            id = i + 1;
            break;
        }
    }
    if (ok) {
        puts("Possible");
        //cout << "Id = " << id << "\n";
        for (int i = 1; i < id; i++) {
            cout << i << "\n";
        }
        for (int i = n - 1; i >= id; i--) {
            cout << i << "\n";
        }
    }
    else puts("Impossible");
}
