#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    long long x,y;
    cin >> x >> y;
    long long ans = 1LL<<60;
    
    //(x,y)=(10,20)
    //(x,y)=(10,5)
    //(x,y)=(10,-5)
    //(x,y)=(10,-20)
    //(x,y)=(10,0)
    //(x,y)=(-10,20)
    //(x,y)=(-10,5)
    //(x,y)=(-10,-5)
    //(x,y)=(-10,-20)
    //(x,y)=(-10,0)
    //(x,y)=(0,10)
    //(x,y)=(0,-10)
    //(x,y)=(0,0)
    
    if(x > 0){
        if(y > 0){
            //cout << ans << endl;
            if(x <= y) ans = y - x;
            else ans = x - y + 2;
        }else if(y < 0){
            ans = x - y;
            if(x >= -y) ans = min(ans, x + y + 1);
            else ans = min(ans , - y - x + 1);
        }else if(y == 0){
            ans = x + 1;
        }
    }else if(x < 0){
        if(y > 0){
            ans = - x + y;
            if(-x <= y) ans = min(ans, y + x + 1);
            else ans = min(ans, - x - y + 1);
        }else if(y < 0){
            if(-x >= -y) ans = - x + y;
            else ans = x - y + 2;
        }else if(y == 0){
            ans = -x;
        }
    }else if(x == 0){
        if(y > 0)ans = abs(y);
        else if(y < 0) ans = abs(y) + 1;
        else if(y == 0)ans = 0;
    }
    
    cout << ans << endl;
}
