#include<bits/stdc++.h>
using namespace std;

int main(){

    int a,b,c,i,j,k;
    cin>>a>>b>>c;

    i=a+b;
    j=a+c;
    k=b+c;

    if(i<j&&i<k){
        cout<<i<<endl;
    }
    else if(j<i&&j<k){
        cout<<j<<endl;
    }
    else{
        cout<<k<<endl;
    }

    return 0;
}