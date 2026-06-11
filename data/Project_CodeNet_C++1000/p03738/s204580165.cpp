#include <bits/stdc++.h>
using namespace std;
using ll=long long;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    string a,b;
    cin>>a>>b;

    ll ans=0;

    if(a.size()>b.size()){
        ans=-1;
    }else if(a.size()<b.size()){
        ans=1;
    }else{
        for(ll i=0;i<a.size();i++){
            if(a[i]>b[i]){
                ans=-1;
                break;
            }
            else if(a[i]<b[i]){
                ans=1;
                break;
            }
        }
    }

    if(ans==-1) cout<<"GREATER"<<endl;
    else if(ans==0) cout<<"EQUAL"<<endl;
    else cout<<"LESS"<<endl;

}
