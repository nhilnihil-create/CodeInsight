#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int b1=0,b2=0,b4=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]%2==1)b1++;
        if(a[i]%4==0)b4++;
        if(a[i]%2==0&&a[i]%4!=0)b2++;
    }
    string ans;
    if(b2==0){
        if(b1<=b4+1) ans="Yes";
        else ans="No";
    }
    else if(b2>0){
        if(b1<=b4) ans="Yes";
        else ans="No";
    }
    cout<<ans<<endl;
}