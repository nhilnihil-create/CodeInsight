#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x,y;
    cin >> x >> y;
    long long cnt = 0;
    if(x == 0){
        if(y > 0){
            cout << y << endl;
            return 0;
        }else if(y < 0){
            cout << abs(y)+1 << endl;
            return 0;
        }
    }

    if(y == 0){
        if(x > 0){
            cout << x+1 << endl;
            return 0;
        }else{
            cout << abs(x) << endl;
            return 0;
        }
    }

    if(abs(x) < abs(y)){
        cnt += abs(y)-abs(x);
        if(x * y < 0){
            cnt += 1;
        }else if(x < 0 && y < 0){
            cnt += 2;
        }
    }else if(abs(x) > abs(y)){
        cnt += abs(x) - abs(y);
        if(x > 0 && y > 0){
            cnt += 2;
        }else if(x * y < 0){
            cnt += 1;
        }
    }else{
        cnt = 1;
    }
    cout << cnt << endl; 
    return 0;
}