#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int a,b,c;
    char op;
    cin>>a>>op>>b;
    if(op=='+'){
        c=a+b;
    }
    else{
        c=a-b;
    }
    cout<<c<<endl;
    return 0;
}
