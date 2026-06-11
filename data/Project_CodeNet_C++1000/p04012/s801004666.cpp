#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 200011
ll s[27];
int main(){
   ll n,i,x,y,k,ans=0;
   string a;
   cin>>a;
   for(i=0;i<a.size();i++){
      s[a[i]-'a']+=1;
   }
   for(i=0;i<27;i++){
      if(s[i]%2!=0){
        cout<<"No"<<endl;
        ans=1;
        break;
      }

   }
   if(ans==0) cout<<"Yes"<<endl;

}



