#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long int a,b;
    char op;
    cin>>a;cin>>op;cin>>b;
    
    if(op=='+'){
        cout<<a+b;
    }
    
    if(op=='-'){
        cout<<a-b;
    }
    return 0;
}