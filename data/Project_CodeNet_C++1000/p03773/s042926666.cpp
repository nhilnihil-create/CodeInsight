#include <iostream>
using namespace std;

int main(){
    int a,b,x = 0;
    cin >> a >> b;
    
    x = a + b;
    
    if(x >= 24){
        x -= 24;
    }
    
    cout << x << endl;
    return 0;
}
