#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    int N, M;
    cin >> N;
    int T[110];
    int t[110];
    for(int i = 1; i <= N; i++) cin >> T[i];
    cin >> M;
    int P[110];
    int X[110];
    for(int i = 1; i <= M; i++) cin >> P[i] >> X[i];
    int k = 1;
    while(k <= M){
        int sum = 0;
        for(int i = 1; i <= N; i++) t[i] = T[i];
        t[P[k]] = X[k];
        for(int j = 1; j <= N; j++) sum += t[j];
        cout << sum << endl;
        k++;
    }
    return 0;
}