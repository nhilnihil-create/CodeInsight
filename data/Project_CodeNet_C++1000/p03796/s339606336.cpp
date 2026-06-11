#include <iostream>
#include <vector>
using namespace std;
int main(void){
    long n;
    cin >> n;
    long ans = 1;
    for(int i = 1;i <= n;i++){
          ans *= i;
          ans %= 1000000007;
    }
    cout << ans << endl;
    
}
