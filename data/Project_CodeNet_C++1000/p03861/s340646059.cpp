#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int a, b, x, n;
    cin >> a >> b >> x;
    long long int ans=0;
    if(a%x!=0){
        a+=(x-a%x);
    }
    if(a<b){
        n=b-a;
        ans=n/x+1;
    }else if(a==b){
        if(a%x==0)
            ans++;
    }
    cout << ans;
}