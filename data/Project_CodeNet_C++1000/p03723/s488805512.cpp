#include <bits/stdc++.h>
using namespace std;

int a, b, c, prevA, prevB, prevC, ans=0;

int main(){
    cin >> a >> b >> c;
    prevA = a;
    prevB = b;
    prevC = c;
    while(a%2==0 && b%2==0 && c%2==0){
        ans++;
        a = (prevB+prevC)/2;
        b = (prevC+prevA)/2;
        c = (prevA+prevB)/2;
        
        if(prevA==a && prevB==b && prevC==c){
            ans = -1;
            break;
        }
        
        prevA=a;
        prevB=b;
        prevC=c;
    }
    cout << ans << endl;
}
 
