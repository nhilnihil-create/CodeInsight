#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll x,y;
    cin>>x>>y;
    if(x<0 && y<0) {
        if(x<y) cout<<y-x;
        else cout<<x-y+2;
    }
    else if(x>=0 && y<0) {
        if(abs(x)<abs(y)) cout<<-(x+y)+1;
        else cout<<x+y+1;
    }
    else if(x<0 && y>=0) {
        if(abs(x)<abs(y)) cout<<x+y+1;
        else {
            if(y==0) cout<<-x;
            else cout<<-(x+y)+1;
        }
    }
    else {
        if(x<y) cout<<y-x;
        else {
            if(y==0) cout<<x+1;
            else cout<<x-y+2;
        }
    }
}