#include <iostream>
using namespace std;
int main(){
    long long x;
    cin >> x;
    int s = x%11;
    long long ans = (x/11)*2;
    if(s==0){
        cout << ans << endl;
        return 0;
    }
    if(s<=6) ans++;
    if(s>6) ans += 2;
    cout << ans << endl;
    return 0;
}

