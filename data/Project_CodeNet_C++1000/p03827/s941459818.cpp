#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x=0,n,i,a[101]={0};
    string s;
    cin>>n;
    cin>>s;

    a[0]=0;

    for(i=0; i<n; i++){
        if(s[i]=='D'){
            x-=1;
            a[i+1]=x;
        }
        else if(s[i]=='I'){
            x+=1;
            a[i+1]=x;
        }
    }
    sort(a,a+n+1);
    cout<<a[n];

    return 0;
}
