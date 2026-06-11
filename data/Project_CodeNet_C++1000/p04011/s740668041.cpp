#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n,k,x,y;
    cin>>n>>k>>x>>y;
    if(n>k)cout<<k*x+y*(n-k)<<endl;
    else cout<<n*x<<endl;
    return 0;
}