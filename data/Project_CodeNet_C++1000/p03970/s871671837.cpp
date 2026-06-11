#include<bits/stdc++.h>
using namespace std;
string a;
string pd="CODEFESTIVAL2016";
int c=16;
int main(){
    c+=1;
    c-=1;
    c+=1;
    c-=1;
    ios::sync_with_stdio(false);
    cin>>a;
    for(int i=0;i<16;i++) c-=(a[i]==pd[i])?1:0;
    cout<<c<<endl;
    return 0;
}