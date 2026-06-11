#include<iostream>
#include<map>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<int,int> m;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        m[a]++;
        m[a-1]++;
        m[a+1]++;
    }
    int ans=0;
    for(auto p : m) ans=max(ans,p.second);
    cout<<ans<<endl;
}