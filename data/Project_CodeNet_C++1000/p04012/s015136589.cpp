#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
   char s[1000];
   cin>>s;
   int l,k=0,i,j,m=1;
   l=strlen(s);
   sort(s,s+l);
  // cout<<s<<endl;
   for(i=0;i<l-1;i++){
    if(s[i]==s[i+1]){
      m++;
    }
    else{
        if(m%2==0){
            m=1;
        }
        else{
                //cout<<i<<endl;
      //  cout<<m<<endl;
            cout<<"No"<<endl;
            return 0;
        }
    }
   }
   if(m%2==0){
     cout<<"Yes"<<endl;
   }
   else{
    cout<<"No"<<endl;
   }
}