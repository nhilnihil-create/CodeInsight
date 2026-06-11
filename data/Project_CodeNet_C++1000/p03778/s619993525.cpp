#include <bits/stdc++.h>
using namespace std;

int main(){
    int w,a,b;
    cin >> w >> a >> b;
    int x;
    if(a <= b){
        x = b - (a+w);
    }else{
        x = a - (b+w);
    }
    if(x < 0){
        cout << 0 << endl;
    }else{
        cout << x << endl;
    }

    return 0;
}

