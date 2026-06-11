#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iterator>
#include<math.h>
#include<cstring>
using namespace std;
void lets_play()
 
{
   int n,m,l,c=0;
   cin>>n>>m>>l;
 
  if(m==7)
    c++;
    if(n==7)
        c++;
    if(l==7)
        c++;
    if(c==1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    }
 
int main()
{
        lets_play();
 
}