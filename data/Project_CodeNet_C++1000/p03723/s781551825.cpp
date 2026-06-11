#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int d = a, e = b, f = c;
    int tempA = a, tempB = b, tempC = c;
    int ans = 0;
    while(tempA % 2 == 0 && tempB % 2 == 0 && tempC % 2 == 0){
        tempA = (b / 2) + (c / 2);
        tempB = (a / 2) + (c / 2);
        tempC = (a / 2) + (b / 2);
        ans++;
        a = tempA;
        b = tempB;
        c = tempC;
        if(tempA % 2  || tempB % 2  || tempC % 2 ){
            break;
        }
        if(tempA == d && tempB == e && tempC == f){
            ans = -1;
            break;
        }
    }
    cout << ans;
    return 0;
}