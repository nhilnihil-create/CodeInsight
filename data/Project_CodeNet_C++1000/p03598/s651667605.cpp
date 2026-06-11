#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int dist = 0;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        int a, b;
        a = 2 * (x - 0);
        b = 2 * (x - K);
        if(b < 0){
            b = -b;
        }
        if(a < b){
            dist += a;
        }else{
            dist += b;
        }
    }
    cout << dist << endl;
}