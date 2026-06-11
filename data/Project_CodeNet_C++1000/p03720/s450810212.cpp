#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(M);
    vector<int> b(M);
    for(int i = 0; i < M; i++){
        cin >> a.at(i) >> b.at(i);
    }
    vector<int> way(N);
    for(int i = 0; i < M; i++){
        for(int j = 1; j <= N; j++){
            if(a.at(i) == j){
                way.at(j - 1)++;
            }
            if(b.at(i) == j){
                way.at(j - 1)++;
            }
        }
    }
    for(int i = 0; i < N; i++){
        cout << way.at(i) << endl;
    }
}