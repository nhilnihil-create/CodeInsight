#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v;
    int ans=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        ans+=a;
        if(a%10!=0) v.push_back(a);
    }
    sort(v.begin(),v.end());
    if(ans%10!=0) cout<<ans<<endl;
    else if(v.size()!=0) cout<<ans-v[0]<<endl;
    else cout<<0<<endl;
}