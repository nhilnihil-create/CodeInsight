#include <iostream>
using namespace std;

int main(){
    int a,b,c,d,x,y;
    cin >> a >> b >> c >> d;
    
    x = a * b;
    y = c * d;
    
    if(x > y){
        cout << x << endl;
    }else if(x < y){
        cout << y << endl;
    }else{
        cout << x << endl;
    }
}
