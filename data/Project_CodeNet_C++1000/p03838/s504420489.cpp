#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
    long x, y;
    cin>>x>>y;
    if(abs(x) > abs(y)){
        if(x < y){
            cout<<min(y-x, 1+(-y-x))<<endl;
        }
        else{
            cout<<min(1+(y+x), 1+(-y+x)+1)<<endl;
        }
    }
    else if(abs(x) < abs(y)){
        if(x < y){
            cout<<min(y-x,1+(y+x))<<endl;
        }
        else{
            cout<<min(1+(-y+x)+1, 1+(-y-x))<<endl;
        }
    }
    else {
        if(x==y)cout<<0<<endl;
        else cout<<1<<endl;
    }
}
