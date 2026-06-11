#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, S;
    cin >> K >> S;
    int count = 0;
    int maxX = min(K, S);
    for (int x = 0; x <= maxX; x++){
        int ypz = S - x;
        if (ypz <= K){
            count += ypz + 1;
        }else if (ypz <= 2 * K){
            count += 2 * K - ypz + 1;
        }
    }
    cout << count << endl;
    return 0;
}
