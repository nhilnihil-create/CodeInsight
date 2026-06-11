#include <iostream>

using namespace std;

int main(){

    int X;
    cin >> X;

    int sum = 0;
    int ans = 0;
    while(sum < X){
        ans ++;
        sum += ans;
    }

    cout << ans << endl;

    return 0;
}