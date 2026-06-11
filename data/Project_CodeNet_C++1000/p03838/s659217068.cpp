#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    long long ans;

    cin>>x>>y;

    if(x > 0 && y > 0){
        if(x > y){
            ans = x - y +2;
        }else{
            ans = y - x;
        }
    }

    else if(x > 0 && y <0){
        ans = abs(x+y)+1;
    }

    else if(x < 0 && y>0){
        ans = abs(y+x)+1;
    }

    else if(x < 0 && y < 0){
        if(x > y){
            ans = abs(y-x)+2;
        }else{
            ans = abs(x-y);
        }
    }

    else if(x == 0 || y == 0){
        if(x == 0 && y > 0){
            ans = y-x;
        }

        else if(x == 0 && y < 0){
            ans = abs(y)+1;
        }

        else if(y == 0  && x > 0){
            ans = x + 1;
        }

        else if( y == 0 && x < 0){
            ans = abs(x);
        }
    }

    cout<<ans<<endl;

    return 0;
}