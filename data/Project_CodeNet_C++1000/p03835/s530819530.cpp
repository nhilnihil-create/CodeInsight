#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int K, S;
    cin >> K >> S;
    ll count = 0;
    for (int x = 0; x <= K; x++)
    {
        for (int y = x; y <= K; y++)
        {
            int z = (S - x - y);
            if(z < y) continue;
            if(z > K) continue;

            if(x != y && y != z){
                count += 6;
            } else if(x == y && y == z){
                count += 1;
            } else {
                count += 3;
            }
            
        }
    }
    
    cout << count << endl;

    return 0;
}
