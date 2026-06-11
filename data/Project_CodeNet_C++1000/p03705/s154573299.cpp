#include <iostream>
using namespace std;
int main(){
    long long n, a, b; cin >> n >> a >> b;
    if(a>b){
        cout << 0 << endl;
        return 0;
    }
    if(n==1){
        if(a!=b) cout << 0 << endl;
        else cout << 1 << endl;
    }else{
        cout << (n-2) * (b-a) + 1 << endl;
    }
    return 0;
}