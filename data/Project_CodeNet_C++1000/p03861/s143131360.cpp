#include<bits/stdc++.h>
using namespace std;

int main(){
    long long a,b,x,p,q;
    cin>>a>>b>>x;
    int cnt=0;
    /*
    for(long long i=a;i<=b;i++){
        if(i%x==0)cnt++;

    }
    cout<<cnt<<"\n";

    */

   /* if(a%x==0){
        int p=a/x + 1;
    }
    else */

    if(a%x==0){
        p = (a/x) - 1 ;
    }
    else
        p=(a/x);

     q = b/x;

    cout<<q-p<<"\n" ;


    return 0;
}
