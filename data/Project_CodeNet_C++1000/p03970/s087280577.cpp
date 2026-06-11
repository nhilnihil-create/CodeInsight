#include<bits/stdc++.h>
using namespace std;
string a,b="CODEFESTIVAL2016";
int c=16;
int main(){
    cin>>a;
    for(int i=0;i<16;i++){
        c-=(a[i]==b[i])? 1:0;
    }
    cout<<c<<endl;
    return 0;
}
