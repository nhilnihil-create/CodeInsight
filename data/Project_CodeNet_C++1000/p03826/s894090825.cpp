#include <iostream>
using namespace std;

int main (void) {
    
    int a, b, c, d;
    int ans1, ans2;

    cin >> a >> b >> c >> d;

    ans1 = a * b;
    ans2 = c * d;


    if (ans1 < ans2 ) {
        cout <<  ans2 << endl;
    }else if (ans1 == ans2) {
        cout << ans1 << endl;
    }else{
        cout << ans1 << endl;
    }

    return 0;
}