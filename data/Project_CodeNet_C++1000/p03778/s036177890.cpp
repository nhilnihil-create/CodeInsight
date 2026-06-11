#include<bits/stdc++.h>
using namespace std;

int main(){
    int w,a,b;
    cin >> w >> a >> b;
    if(a-w<=b&&b<=a+w)cout << 0 << endl;
    else{
        cout << abs(b-a)-w << endl;
    }
    return 0;
}