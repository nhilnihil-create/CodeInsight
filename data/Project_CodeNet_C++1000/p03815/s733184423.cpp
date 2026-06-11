#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x; cin >> x;
    long long count;
    count=x/11*2;
    if (x%11!=0){//余りがあって
        if (x%11<=6) count++;
        else count+=2;
    }
    /*if (x<=6){
        cout << 1 << endl;
    } else if (x<=11){
        cout << 2 << endl;
    } else {
        cout << (x/11)*2+1 << endl;
    }*/
    cout << count << endl;
    return 0;
}