#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    
    int N, M;
    cin >> N >> M;
    
    int ans[51] = {};
    for(int i=0; i < M; i++){
        int a, b;
        cin >> a >> b;
        ans[a]++;
        ans[b]++;
    }
    
    for(int i=1; i <= N; i++){
        cout << ans[i] << endl;
    }
}