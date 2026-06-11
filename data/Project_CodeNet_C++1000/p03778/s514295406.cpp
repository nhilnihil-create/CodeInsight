#include<bits/stdc++.h>
using namespace std;
int main(){
    int w,a,b;
    cin >> w >> a >> b;
    if(a<=b){
        if(b>(a+w)){
        cout << abs(b-(a+w)) << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    else{
        if(a>(b+w)){
        cout << abs(a-(b+w)) << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    return 0;
}