#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
    int K, S;
    cin >> K >> S;
    int count = 0;
    for(int i = 0; i <= K; i++){
        for(int j = 0; j <= K; j++){
            int z = S - (i + j);
            if(z < 0 || z > K) continue;
            count++;
        }
    }

    cout << count << endl;

    return 0;
}

