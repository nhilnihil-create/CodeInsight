#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    if(a == b && b == c && a % 2 == 0) ans = -1;
    else{
        while(a % 2 == 0 && b % 2 == 0 && c % 2 == 0){
            ans++;
            int t1 = b/2 + c/2;
            int t2 = a/2 + c/2;
            int t3 = a/2 + b/2;
            a = t1;
            b = t2;
            c = t3;
        }
    }
    cout << ans << endl;
    return 0;
}