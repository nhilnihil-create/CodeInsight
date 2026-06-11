#include <bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,c;
    cin >> a >> b >> c;
    int cnt = 0;
    while(true){
        if(a%2==1)break;
        if(b%2==1)break;
        if(c%2==1)break;
        long long tmpA = a/2, tmpB = b/2, tmpC = c/2;
        a+=tmpB+tmpC;
        b+=tmpA+tmpC;
        c+=tmpA+tmpB;
        if((a==b)&&(b==c)){
            cout << -1 << endl;
            return 0;
        }
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}