#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int A, B;
    cin >> A >> B;
    int ans = A + B;
    if(ans < 24)
    {
        cout << ans << endl;
    }
    if(ans > 24)
    {
        int ans1  = ans - 24;
        cout << ans1 << endl;
    }
    if(ans == 24)
    {
    int ans2 = 0;
    cout << ans2 << endl;
    }
}

