#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y;
    cin >> x >> y;
    int d;
    if(x<y){
        if(y<=0 || x>=0) d=y-x;
        else d=abs(y+x)+1;
    }
    else{
        if(y>0 || x<0) d=2+x-y;
        else d=abs(-y-x)+1;
    }

    cout << d << "\n";
    return 0;
}