#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,a,b;
    cin>>n>>a>>b;
    cout<<max((n-2)*(b-a)+1,(long long)0)<<endl;
    return(0);
}