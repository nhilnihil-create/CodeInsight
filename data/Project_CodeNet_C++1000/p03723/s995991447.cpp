#include<bits/stdc++.h>
using namespace std;
int main(){
 int a,b,c;
 cin>>a>>b>>c;
 int count=0;
 if(a==b&&b==c&&a==c&&a%2==0&&b%2==0&&c%2==0) cout<<-1<<endl;
 else {
 while(a%2==0&&b%2==0&&c%2==0){
   int m=a,n=b;
   a=b/2+c/2;
   b=m/2+c/2;
   c=m/2+n/2;
   count++;
 }
 cout<<count<<endl;
 }
}