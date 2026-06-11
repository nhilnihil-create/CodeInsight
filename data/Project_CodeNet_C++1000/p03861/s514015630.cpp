#include <iostream>
using namespace std;

void solve(){
    long long a, b, x; cin >> a >> b >> x;
    long long total = b/x+1;//0-bまでで割り切れるもの
    long long totala = (a-1)/x+1;//0~a-1までで割り切れるもの
    if(a == 0) totala = 0;
    cout << total-totala << endl;
}

int main(){
    solve();
    return 0;
}