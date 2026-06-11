#include<bits/stdc++.h>
#define int long long
#define log(x,b) (log(x)/log(b))
using namespace std;

int32_t main()
{
    int n,x;
    cin>>n>>x;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;cin>>x;v.push_back(x);
    }
    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(v[i]>=x)cnt+=v[i]-x,v[i]=x;
        int b=v[i]+v[i+1];
        if(b>=x){
            if(b-x>=v[i+1]){
                cnt+=v[i+1];
                v[i+1]=0;
            }
            else{
                cnt+=b-x;
                v[i+1]-=b-x;
            }
        }
    }

    cout<<cnt<<endl;

    return 0;
}
