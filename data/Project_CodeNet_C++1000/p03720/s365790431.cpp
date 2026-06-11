#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<int> v(N,0);
    
    for (int i = 0; i < M; i++){
        int a=0, b=0; cin >> a >> b;

        for (int j = 0; j < N; j++){
            if (a == j+1) v.at(j)++; 
            if (b == j+1) v.at(j)++;
        }
    }

    for (int i = 0; i < N; i++) cout << v.at(i) << endl;
}