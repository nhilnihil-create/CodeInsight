#include <iostream>
using namespace std;

int main (void) {
    
    int a, b, c; // ペンキの色
    int cnt; //個数

    cin >> a >> b >> c;

    // AtCoDeerくんが買ったペンキの色の種類を知りたい
        if (a == b && b == c ){
            cnt = 1;
         }
        else if (a == b && b != c ){
            cnt = 2;
             }
        else if (a != b && b == c){
            cnt = 2;
        }
        else if (a == c && c != b){
            cnt = 2;
        }
        else{
            cnt = 3;
        }

    cout << cnt;

    return 0;
}
