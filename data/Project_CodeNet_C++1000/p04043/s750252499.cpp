#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[3],t=0,k=0;
    for(int i=0;i<3;i++){
        cin>>a[i];
        if(a[i]==5)
         t++;
        else if(a[i]==7)
         k++;
    }
    if(t==2 && k==1)
     cout<<"YES";
     else 
      cout<<"NO";
      return 0;
}
     
   