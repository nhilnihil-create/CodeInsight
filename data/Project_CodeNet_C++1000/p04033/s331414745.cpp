#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    string ans="Zero";

    if(a>0) ans="Positive";
    else if(b>0) ans="Zero";
    else if(b<0){
        if((a-b)%2) ans="Positive";
        else ans="Negative";
    }
    cout << ans << endl;
}