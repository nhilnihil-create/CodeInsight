#include<bits/stdc++.h>
using namespace std;

int main(){

   char a,b;
   int ans=1;
   cin>>a>>b;
   if(a=='D') ans*=-1;
   if(b=='D') ans*=-1;

    cout<<(ans==1?"H":"D")<<endl;




    return 0;
}