#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(3*max(max(a,b),c)+3*min(min(a,b),c)==2*a+2*b+2*c){
    cout<<"YES";
    return 0;
    }
    cout<<"NO";
    return 0;
}