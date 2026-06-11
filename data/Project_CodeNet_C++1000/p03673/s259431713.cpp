#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
int S [512345];
int main() {
    int N;
    int left =212345 , right = left +1;
    cin >> N;
    vector<int> A(N);
    
    rep(i, 0, N){
        cin >> A[i];
    }
    rep(i, 0, N){
        if (i%2 == (N-1)%2){
            S[left--] = A[i];
        } else {
            S[right++] = A[i];
        }
    }
    for(int i = left+1; i<right; i++){
        cout << S[i] << " ";
    }
    
    return 0;
}
