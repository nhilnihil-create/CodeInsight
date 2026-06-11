#include <iostream>
using namespace std;
int main(void){
    int a, b, h;
    cin >> a;
    cin >> b;
    cin >> h;
    
    if(h%2 == 0){
       int ans = (a+b)*h/2;
        cout << ans << endl;
    }
    
}
