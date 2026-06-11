#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    vector<int> A(N);
    int cntOdd = 0, cntOver4 = 0;
    for(int i = 0; i < N; ++i){
        cin >> A[i];
        if(A[i]%2 == 1) cntOdd++;
        else{
            int x = A[i]/2;
            if(x%2 == 0) cntOver4++;
        }
    }
    
    if(N%2 == 1 && cntOdd == cntOver4 + 1 || cntOdd <= cntOver4) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return 0;
}