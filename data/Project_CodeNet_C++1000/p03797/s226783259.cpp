#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    long long int n,k,ans=0;
    cin>>n>>k;
    if(2*n>=k){
        ans=k/2;
    }
    else{
        ans=n;
        k-=2*n;
        ans+=k/4;
    }
    cout<<ans<<endl;
    return 0;
}