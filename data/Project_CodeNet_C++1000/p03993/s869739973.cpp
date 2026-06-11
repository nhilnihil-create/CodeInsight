#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    int ans=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[a[i]]==i)ans++;
    }
    cout<<ans/2<<endl;
    return 0;
}