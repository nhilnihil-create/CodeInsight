#include <bits/stdc++.h>
using namespace std;
long a,b,c,d,e,f,g,num,x,y;

int main(){
    cin >> a >> b >> c >> d >> e >> f >> g;
    num = min({a,d,e});
    x = 3*num + (a-num)/2*2 + (d-num)/2*2 + (e-num)/2*2;
    if(num) num--;
    y = 3*num + (a-num)/2*2 + (d-num)/2*2 + (e-num)/2*2;
    cout << max(x,y) + b << endl;
}