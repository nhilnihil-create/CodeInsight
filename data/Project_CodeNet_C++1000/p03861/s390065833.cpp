#include<bits/stdc++.h>
using namespace std;

int main(){
    long long a,b,x;
    cin >> a >> b >> x;
    long long c,d;
    if(a == 0){
        c = 0;
    }else{
        c = (a-1)/x+1;
    }
    d = b/x+1;

    cout << d - c << endl;
    return 0;
}