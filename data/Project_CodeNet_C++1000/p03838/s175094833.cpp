#include<bits/stdc++.h>
using namespace std;
int main(){
    long x,y;
    cin >> x >> y;
    long ans = 0;
    if(x==0){
        x += abs(y);
        ans += abs(y);
    }
    
    if(y-x == abs(abs(y)-abs(x))){
        ans += y-x;
    }else if(y+x ==abs(abs(y)-abs(x)) || -y-x == abs(abs(y)-abs(x))){
        ans += abs(abs(y)-abs(x))+1;
    }else{
        ans += abs(abs(y)-abs(x))+2;
    }




    cout << ans << endl;

}