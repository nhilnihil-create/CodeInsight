#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    string ans;
    if(a < 0 && b >= 0) ans = "Zero";
    if(b < 0){
        int tmp = abs(b - a) + 1;
        if(tmp % 2 == 0) ans = "Positive";
        else ans = "Negative";
    }

    else if(b > 0){
        int tmp;
        if(a < 0){
            ans = "Zero";
        }
        else if(a > 0) ans = "Positive";
    }

    if(a == 0 || b == 0) ans = "Zero";

    cout<<ans<<endl;

    return 0;
}