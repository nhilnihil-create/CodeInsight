#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    cin>>a>>b>>c;
    if(a+b==c || c+b==a || a+c==b)
     cout<<"Yes";
    else 
     cout<<"No";
     return 0;
}
     
   