#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> a(M), b(M), cities(N);

    for(int i = 0; i < M; i++){
        cin >> a[i] >> b[i];
    }
    for(int i = 0; i < M; i++){
        cities[a[i] - 1]++;
        cities[b[i] - 1]++;
    }
    for(int j = 0; j < N; j++){
        cout << cities[j] << endl;
    }
}