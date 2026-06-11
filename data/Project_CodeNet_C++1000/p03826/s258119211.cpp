#include<bits/stdc++.h>
using namespace std;
int main(){
unsigned long long int a,b,c,d,e,f;
cin>>a>>b>>c>>d;
if((a*b)==(c*d)){
    cout<<(a*b)<<endl;
}
else{
    e=a*b;
    f=c*d;
    if(e>f){
        cout<<e<<endl;
    }
    else{
        cout<<f<<endl;
    }
}
return 0;
}
