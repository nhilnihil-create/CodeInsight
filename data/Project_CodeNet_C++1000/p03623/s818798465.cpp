#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long  x,a,b;
    cin>>x>>a>>b;
    if(abs(x-a)>abs(x-b))
     cout<<"B";
    else 
     cout<<"A";
    return 0;
}
     
   