#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, sum = 0;
    cin >> N >> K;
    
    for(int i = 0; i < N; i++){
        int x, dist = 0;
        cin >> x;

        if(std::abs(K - x) < x){
            dist = std::abs(K - x);
        }else{
            dist = x;
        }
        sum += 2 * dist;
    }

    cout << sum << endl;
}
