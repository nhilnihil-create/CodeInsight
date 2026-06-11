#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)cin>>a[i];
    bool flag=false;
    int j=1;
    int ans=0;
    for(int i=0;i<n;i++){
        j=a[j];
        ans++;
        if(j==2){
            cout<<ans<<endl;
            flag=true;
            break;
        }
    }
    if(!flag)cout<<-1<<endl;
    return 0;
}