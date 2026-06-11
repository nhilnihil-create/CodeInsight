#include <bits/stdc++.h>
//#include <iostream>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;

int main() {
    int N,x; cin>>N>>x;
    if(x==1||x==2*N-1){
        cout<<"No"<<endl;
        return 0;
    }

    if(N==2){
        cout<<"Yes"<<endl;
        cout<<"1\n2\n3"<<endl;
        return 0;
    }

    vector<int> ans(2*N-1,0);
    ans[N-1]=x;
    if(x==2){
        ans[N]=x-1;
        ans[N+1]=x+1;
        ans[N-2]=x+2;
        int itr=0;
        for (int i = 5; i <= 2 * N - 1; ++i) {
            while(ans[itr]!=0){
                ++itr;
            }
            ans[itr]=i;
            ++itr;
        }
    }else{
        ans[N]=x+1;
        ans[N+1]=x-2;
        ans[N-2]=x-1;
        int itr=0;
        for (int i = 1; i <= 2 * N - 1; ++i) {
            if(i>=x-2&&i<=x+1){
                continue;
            }
            while(ans[itr]!=0){
                ++itr;
            }
            ans[itr]=i;
            ++itr;
        }
    }
    cout<<"Yes"<<endl;
    for (int i = 0; i < 2*N-1; ++i) {
        cout<<ans[i]<<endl;
    }


    return 0;
}
