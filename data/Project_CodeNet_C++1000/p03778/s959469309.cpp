#include <iostream>
using namespace std;

int main(){
    int w, a, b;
    cin >> w >> a >> b;
    if(a > b){
        int t = a; a = b; b = t;
    }
    if(b-(a+w) > 0) cout << b-(a+w) << endl;
    else cout << 0 << endl;
    return 0;
}