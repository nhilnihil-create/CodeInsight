#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int a,b;
    cin >> a >> b;
    string ans;
    if(a <= 0 && 0<=b){
        ans = "Zero";
    }
    else if(a > 0 && b >0){
        ans = "Positive";
    }
    else{
        if((b-a+1)%2==0) ans = "Positive";
        else ans = "Negative";
    }
    cout << ans << endl;
    return 0;
}