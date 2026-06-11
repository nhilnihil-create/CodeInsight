#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k,x,y,s,c,s1,s2;
    cin>>n>>k>>x>>y;
    if(n>=k){s=n-k;c=k;}
    else if(n<k){c=n;s=0;}
    s1=x*c;
    s2=y*s;
    cout<<s1+s2;

    return 0;
}
