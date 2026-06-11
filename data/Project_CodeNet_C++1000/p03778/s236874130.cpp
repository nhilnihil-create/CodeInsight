#include <bits/stdc++.h>
using namespace std;
 
int a, b, w, x, y;
 
int main () {
cin >> w >> a >> b;
if(a>b+w){
    y=a-(b+w);
     cout << y << endl;
}else if (b>a+w){
    x=b-(a+w);
    cout << x << endl;
    }else{
    cout << 0 << endl;
    }
}

