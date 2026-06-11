#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> G[N], c(N, 0);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        c[a]++;
        c[b]++;
    }
    for(int i = 0; i < N; i++){
        if(c[i] % 2 == 1){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}