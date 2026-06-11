#include<bits/stdc++.h>
using namespace std;
int main()
{
   long n,h,w;
    cin>>n>>h;
    w=n+h;
    if(w%3!=0 && n%3!=0 && h%3!=0) cout<<"Impossible"<<endl;
    else  cout<<"Possible"<<endl;


  return 0;
}
