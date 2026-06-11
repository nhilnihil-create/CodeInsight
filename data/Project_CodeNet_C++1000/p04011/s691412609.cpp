#include<iostream>
#include<math.h>
using namespace std;

#define ll long long
int main(){

int n,k,x,y;
cin>>n>>k>>x>>y;

int total=0;
if(n<=k)
{
    
    total=x*(n);
}else{
    total=k*x;
    total+=y*(n-k);
}
cout<<total;

}
