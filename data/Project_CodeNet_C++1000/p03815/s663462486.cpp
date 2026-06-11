#include <bits/stdc++.h>
using namespace std;

int main(){
    long long X;
    long long ans = 0;
    cin>>X;

    long long cnt = X/11;
    ans += cnt*2;

    X -= cnt*11;

    int i=0;

    while(X > 0){
        if(i%2 == 0) X -= 6;
        else X -= 5;
        i++;
    }

    ans += i;
    
    cout<<ans<<endl;

    return 0;
}