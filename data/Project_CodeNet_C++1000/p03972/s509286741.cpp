#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w,h,s[100000],t[100001],ans,a;
vector<ll>v;
int main(void){
    cin>>w>>h;
    for(int i=0;i<w;i++){
        cin>>a;
        v.push_back(a);
        ans+=a;
    }
    for(int i=0;i<h;i++){
        cin>>s[i];
    }
    //cout<<ans<<endl;
    sort(v.begin(),v.end());
    for(int i=0;i<w;i++)t[i+1]=t[i]+v[i];
    for(int i=0;i<h;i++){
        a=lower_bound(v.begin(),v.end(),s[i])-v.begin();
        //cout<<w+1<<a<<endl;
        //cout<<(w+1)<<" "<<a<<" "<<s[i]<<" "<<t[a]<<" "<<endl;
        ans+=(w-a+1)*s[i]+t[a];
        //
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
}
