#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int k;
    int x;
    int moveCount = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> x;
        
        if (x < k - x) {
            moveCount += x;
        }
        else
        {
            moveCount += k - x;
        }
   }
    
    cout << moveCount * 2 << endl;
}