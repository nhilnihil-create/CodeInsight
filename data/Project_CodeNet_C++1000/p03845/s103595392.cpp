#include <iostream>
#include <array>

using namespace std;

int main(){
    int N, M, k, val, sum = 0, ans;

    array<int, 100> p;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> p[i];
        sum += p[i];
    }

    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> k >> val;
        cout << sum + val - p[k - 1] << '\n';
    }
    
}
