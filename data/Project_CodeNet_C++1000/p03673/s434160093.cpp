#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    deque<int> b;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (i % 2 == 0) b.push_back(a);
        else b.push_front(a);
    }
    
    if (n % 2 == 1) {
        for (int i = n - 1; i >= 0; i--)
        {
            if (i != 0)
                cout << b[i] << " ";
            else
                cout << b[i];
        }
        
    } else {
        for (int i = 0; i < n; i++)
        {
            if (i != n - 1)
                cout << b[i] << " ";
            else
                cout << b[i];
        }
    }
    cout << endl;
    return 0;
}