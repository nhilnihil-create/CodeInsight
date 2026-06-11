#include <iostream>
using namespace std;
int main(){
    int a; cin >> a;
    int i = 0, ans = 0;
    while(i<2){
        int x; cin >> x;
        ans += min(a,x);
        a = max(a,x);
        i++;
    }
    cout << ans << endl;
    return 0;
}