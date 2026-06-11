#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n,m;
    cin>>n;
    int t[n];
    for(int i=0;i<n;i++)cin>>t[i];
    cin>>m;
    int p,x;
    for(int i=0;i<m;i++){
        cin>>p>>x;
        int ans=0;
        for(int i=0;i<n;i++){
            if(i!=p-1)ans+=t[i];
            else ans+=x;
        }
        cout<<ans<<endl;
    }
    return 0;
}