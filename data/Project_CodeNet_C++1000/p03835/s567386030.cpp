#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B, C, D, E;
    cin >> A >> B;
    int ans = 0;
    for (size_t i = 0; i <= A; i++)
    {
        for (size_t j = 0; j <= A; j++)
        {
            if (B-i-j>=0 && B-i-j<=A)
            {
                ans++;
            //    cout << i << endl;
            //    cout << j << endl;
            }
            
        }
        
    }
    cout << ans << endl;
    
    return 0;
}