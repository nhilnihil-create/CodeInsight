#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int x = c-a;
    int y = d-b;
    //一回目の操作
    cout << string(x,'R') << string(y,'U');
    cout << string(x,'L') << string(y,'D');

    //二回目の操作
    cout << 'D' << string(x+1,'R') << string(y+1,'U') << 'L';
    cout << 'U' << string(x+1,'L') << string(y+1,'D') << 'R';
    cout << endl;
    return 0;
}



