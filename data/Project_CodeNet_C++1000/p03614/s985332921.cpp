#include <iostream>
using namespace std;

const int maxN = 1e5+100;

int n, a[maxN], ans;

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) 
        cin >> a[i];
    for(int i=1; i<=n; i++) 
        if (a[i] == i) {
            ++ans;
            if (a[i+1] == i+1)
                i++;
        }
    cout << ans;
}
