#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a,c,b;
    cin>>a>>b>>c;
    long long k=b-a,t=c-b;
    if(k<0 || t<0 )
    { k=k*-1;t=t*-1;}
    
    if(t==k)
     cout<<"YES";
    else 
     cout<<"NO";
    return 0;
}
     
   


