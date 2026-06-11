#include <iostream>
using namespace std;

int main(){
    int N, K, X, Y;
    cin >> N >> K >> X >> Y;

    int fee=0;
    if(N>K) fee=K*X+(N-K)*Y;
    else fee=N*X;

    cout << fee << endl;

    return 0;
}