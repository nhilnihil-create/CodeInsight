#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define MAX(a,b) a=a>b?a:b
#define MIN(a,b) a=a<b?a:b
#define REP(i,x,n) for(int i=x;i<n;i++)
#define REPR(i,x,n) for(int i=n-1;i>=x;i--)
#define pb  push_back
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLr(obj) (obj).rbegin(), (obj).rend()
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int, int> P;


int main(){
   ll n;
   string s;
   cin>>n>>s;
   string ans,anss,answ;
   bool f=1,fw=1;
   
   if(s[1]=='o')ans="WSW";
   else ans="WSS";
   REP(i,2,n-1){
      if(ans[i]=='S')
      if(s[i]=='o')ans+=ans[i-1];
      else ans+=(ans[i-1]=='W'?'S':'W');
      if(ans[i]=='W')
      if(s[i]=='x')ans+=ans[i-1];
      else ans+=(ans[i-1]=='W'?'S':'W');
   }
   if(ans[0]=='S'){
      if(s[0]=='o'){if(ans[n-1]!=ans[1])f=0;}
      else{ if(ans[n-1]==ans[1])f=0;}
   }
   else if(ans[0]=='W'){
      if(s[0]=='x'){if(ans[n-1]!=ans[1])f=0;}
      else {if(ans[n-1]==ans[1])f=0;}
   }
   if(ans[n-1]=='S'){
      if(s[n-1]=='o'){if(ans[0]!=ans[n-2])f=0;}
      else{ if(ans[0]==ans[n-2])f=0;}
   }
   else if(ans[n-1]=='W'){
      if(s[n-1]=='x'){if(ans[0]!=ans[n-2])f=0;}
      else {if(ans[n-2]==ans[0])f=0;}
   }
      

   if(!f){
      f=1;
      if(s[1]=='o')ans="SSS";
   else ans="SSW";
   REP(i,2,n-1){
      if(ans[i]=='S')
      if(s[i]=='o')ans+=ans[i-1];
      else ans+=(ans[i-1]=='W'?'S':'W');
      if(ans[i]=='W')
      if(s[i]=='x')ans+=ans[i-1];
      else ans+=(ans[i-1]=='W'?'S':'W');
   }
   if(ans[0]=='S'){
      if(s[0]=='o'){if(ans[n-1]!=ans[1])f=0;}
      else{ if(ans[n-1]==ans[1])f=0;}
   }
   else if(ans[0]=='W'){
      if(s[0]=='x'){if(ans[n-1]!=ans[1])f=0;}
      else {if(ans[n-1]==ans[1])f=0;}
   }
   if(ans[n-1]=='S'){
      if(s[n-1]=='o'){if(ans[0]!=ans[n-2])f=0;}
      else{ if(ans[0]==ans[n-2])f=0;}
   }
   else if(ans[n-1]=='W'){
      if(s[n-1]=='x'){if(ans[0]!=ans[n-2])f=0;}
      else {if(ans[n-2]==ans[0])f=0;}
   }
   }
   if(!f){
      f=1;
      if(s[1]=='o')ans="SWW";
   else ans="WWW";
   REP(i,2,n-1){
      if(ans[i]=='S')
      if(s[i]=='o')ans+=ans[i-1];
      else ans+=(ans[i-1]=='W'?'S':'W');
      if(ans[i]=='W')
      if(s[i]=='x')ans+=ans[i-1];
      else ans+=(ans[i-1]=='W'?'S':'W');
   }
   if(ans[0]=='S'){
      if(s[0]=='o'){if(ans[n-1]!=ans[1])f=0;}
      else{ if(ans[n-1]==ans[1])f=0;}
   }
   else if(ans[0]=='W'){
      if(s[0]=='x'){if(ans[n-1]!=ans[1])f=0;}
      else {if(ans[n-1]==ans[1])f=0;}
   }
   if(ans[n-1]=='S'){
      if(s[n-1]=='o'){if(ans[0]!=ans[n-2])f=0;}
      else{ if(ans[0]==ans[n-2])f=0;}
   }
   else if(ans[n-1]=='W'){
      if(s[n-1]=='x'){if(ans[0]!=ans[n-2])f=0;}
      else {if(ans[n-2]==ans[0])f=0;}
   }
   }
   if(!f){
      f=1;
      if(s[1]=='o')ans="WWS";
      else ans="SWS";
   REP(i,2,n-1){
      if(ans[i]=='S'){
         if(s[i]=='o')ans+=ans[i-1];
         else ans+=(ans[i-1]=='W'?'S':'W');
      }
      
      if(ans[i]=='W'){
         if(s[i]=='x')ans+=ans[i-1];
         else ans+=(ans[i-1]=='W'?'S':'W');
      }
      
   }
   if(ans[0]=='S'){
      if(s[0]=='o'){if(ans[n-1]!=ans[1])f=0;}
      else{ if(ans[n-1]==ans[1])f=0;}
   }
   else if(ans[0]=='W'){
      if(s[0]=='x'){if(ans[n-1]!=ans[1])f=0;}
      else {if(ans[n-1]==ans[1])f=0;}
   }
   if(ans[n-1]=='S'){
      if(s[n-1]=='o'){if(ans[0]!=ans[n-2])f=0;}
      else{ if(ans[0]==ans[n-2])f=0;}
   }
   else if(ans[n-1]=='W'){
      if(s[n-1]=='x'){if(ans[0]!=ans[n-2])f=0;}
      else {if(ans[n-2]==ans[0])f=0;}
   }
   }

   if(f){
      cout<<ans<<endl;
   }
   else{
      cout<<-1<<endl;
   }
   
}
