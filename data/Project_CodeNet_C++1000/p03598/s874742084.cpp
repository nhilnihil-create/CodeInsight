#include<iostream>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int a;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>a;
        ans+=min(2*a,2*(k-a));
    }
    cout<<ans<<endl;
    return 0;
}