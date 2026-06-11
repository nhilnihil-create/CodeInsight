#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n ; i++)

int main(){
    int N, K;
    cin >> N >> K;
    int sum = 0;

    rep(i, N){
        int x;
        cin >> x;

        int A = x;
        int B = K - x;

        if(A < B){
            sum += 2*A;
        } else{
            sum += 2*B;
        }
    }

    cout << sum << endl;
}