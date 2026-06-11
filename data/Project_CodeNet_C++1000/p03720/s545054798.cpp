#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,M;
    cin >> N >> M;
    vector<int> A(N);
    for(int i = 0; i < M; ++i){
        int a, b;
        cin >> a >> b;
        a--; b--;
        A[a]++, A[b]++;
    }
    for(int i = 0;i < N; ++i){
        cout << A[i] << endl;
    }
    return 0;
}