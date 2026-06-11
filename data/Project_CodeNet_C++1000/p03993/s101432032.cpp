#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    vector<int> A(N); 
    for(int i = 0; i < N; ++i){
        cin >> A[i];
        A[i]--;
    }
    int ret = 0;
    for(int i = 0; i < N; ++i){
        if(A[A[i]] == i) ret++;
    }
    cout << ret/2 << endl;
    return 0;
}