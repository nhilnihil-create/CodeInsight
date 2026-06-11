#include <iostream>
using namespace std;
int main(){
    int n, ans=1;
    cin >> n;
    while(ans<=n){
        ans *= 2;
        if(ans>n){
            ans /= 2;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}