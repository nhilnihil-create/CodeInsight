#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int n,k,x,y;
    cin>>n>>k>>x>>y;
    if(k>n)k=n;
    int sum=(k*x)+(n-k)*y;
    cout<<sum;
}