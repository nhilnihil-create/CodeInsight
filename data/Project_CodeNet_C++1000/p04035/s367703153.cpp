#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i;
cin>>n;
lli a[n],l;
cin>>l;
for(i=0;i<n;i++){
    cin>>a[i];
    
}
int val=0;
int nonbreak=0;
   for(i=0;i<n-1;i++){
       if((a[i]+a[i+1])>=l){
           val=1;
           nonbreak=i+1;
           break;
           
           
       }
   }
   if(val==0) {cout<<"Impossible\n";}
   else{
       cout<<"Possible\n";
       for(i=1;i<nonbreak;i++){
           cout<<i<<"\n";
       }
       for(i=n-1;i>=nonbreak;i--){cout<<i<<"\n";}
       
   }
   
   
	return 0;
}
