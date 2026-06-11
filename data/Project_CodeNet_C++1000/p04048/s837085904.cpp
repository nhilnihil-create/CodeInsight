#include<bits/stdc++.h>
using namespace std;

int main(){
    size_t N, X;
    cin >> N >> X;
    size_t ans{N};
    N -= X;
    while(X){
        ans += 2 * X * (N / X);
        swap(N %= X, X);
    }
    cout << ans - N << endl;
    return 0;
}