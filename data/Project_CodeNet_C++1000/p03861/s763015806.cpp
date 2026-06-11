#include<iostream>
using namespace std;
int main()
{ long long int n,m,x;
 cin>>n>>m>>x;
 long long int t =(m/x)-(n/x);
 if(n%x==0)
       t=t+1;
 cout<<t;
}
