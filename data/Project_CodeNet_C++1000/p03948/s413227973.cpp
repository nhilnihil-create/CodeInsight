#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;

int H,W,N;

int main(){
    int N,T; cin>>N>>T;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin>>a[i];
    }

    int mini=a[0],maxval=0,cnt=0;

    for (int i = 1; i < N; ++i) {
        if(a[i]<mini) mini=a[i];
        if(a[i]-mini>maxval){
            maxval=a[i]-mini;
            cnt=1;
        }else if(a[i]-mini==maxval){
            cnt++;
        }
    }
    cout<<cnt<<endl;

    return 0;
}