#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;
typedef int64_t ll;


int main() {
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i <= M; i++){
        for (int j = 0; j <= N; j++){
            if (N * i + M * j - 2 * i * j == K){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
