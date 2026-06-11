#include <iostream>
using namespace std;
int main(void){
    // Your code here!
  int A, B, C, D;
    cin >> A >> B >> C >> D;
    int ans1 = A * B;
    int ans2 = C * D;
    
    if (ans1 > ans2)
    {
    cout << ans1 <<endl;
    }
    if(ans1 < ans2)
    {
        cout << ans2 <<endl;
    }
    if(ans1 == ans2)
    {
        cout << ans1 << endl;
    }
    
}
