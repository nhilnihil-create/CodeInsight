#include <iostream>
using namespace std;

int main(){
    int a,b,c,x = 0,y = 0;
    cin >> a >> b >> c;
    
    x = b - a;
    y = c - b;
    
    if(x == y){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    
    
    return 0;
}
