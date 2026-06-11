#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);i++)
using ll=long long;

int main() {
    int n;
    cin>>n;
    int max_num=0;
    int ans=0;
    

    rep(i,n){
        int cnt=0;
        int num=i;
        while(true){
            bool exist_odd=false;
            if(num%2!=0)exist_odd=true;
            if(exist_odd){
                //cout<<i;
                break;
            }
            num/=2;
            cnt++;
        }
        
        max_num=max(cnt,max_num);
        if(max_num==cnt)ans=i;

    }
    cout<<ans;
    return 0;
    }
