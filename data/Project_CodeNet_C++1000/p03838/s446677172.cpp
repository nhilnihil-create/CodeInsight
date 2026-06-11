#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    cin >> x >> y;
    if(x>=0&&y>=0){
        if(x<y){
            cout << abs(abs(x)-abs(y)) << endl;
        }
        else{
            if(y==0)cout << abs(abs(x)-abs(y))+1 << endl;
            else cout << abs(abs(x)-abs(y))+2 << endl;
        }
    }
    else if(x<0&&y>=0){
        if(y==0)cout << abs(abs(x)-abs(y)) << endl;
        else cout << abs(abs(x)-abs(y))+1 << endl;
    }
    else if(x>=0&&y<0){
        if(x==0)cout << abs(abs(x)-abs(y))+1 << endl;
        else cout << abs(abs(x)-abs(y))+1 << endl;
    }
    else{
        if(x<y){
            cout << abs(abs(x)-abs(y)) << endl;
        }
        else{
            cout << abs(abs(x)-abs(y))+2 << endl;
        }
    }
    return 0;
}