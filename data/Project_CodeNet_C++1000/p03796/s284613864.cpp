#include <iostream>

using namespace std;

int main(){
    int n;
    long long p = 1;

    cin >> n;
    for(int i = 1; i <= n; i++){
        p *= i;
        if(p >= 1000000007) p %= 1000000007;
    }
    cout << p << endl;
}
