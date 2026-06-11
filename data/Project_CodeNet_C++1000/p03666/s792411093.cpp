#include <iostream>
using namespace std;
int main(void){
    int n;
    long long a, b, c, d, x;
    cin >> n >> a >> b >> c >> d;
    x = abs(a-b);
    n--;
    if(x > n*d){
        cout << "NO" << endl;
        return 0;
    }
    long long m = (x+n*d) / (c+d);
    if(x <= m*d - (n-m)*c){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
