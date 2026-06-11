#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    cin>>a>>b>>c;
    if(c>a && c<b)
     cout<<"Yes";
    else if(c==a && c==b && a==b)
     cout<<"Yes";
    else 
     cout<<"No";
     return 0;
}
     
   


