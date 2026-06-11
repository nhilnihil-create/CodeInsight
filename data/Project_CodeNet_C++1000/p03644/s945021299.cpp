#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int tmp = 1;
    int ans = 0;

    cin >> n;

    if(n == 1){
        cout << 1;
    }else{
        while(tmp <= n){
            tmp *= 2;
        }
        cout << tmp/2;
    }
    return 0;
}