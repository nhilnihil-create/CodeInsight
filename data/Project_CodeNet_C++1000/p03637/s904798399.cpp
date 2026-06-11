#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;

int main() {
    int N; cin>>N;
    vector<ll>A(N);
    int cnt4=0, cnt2=0,cnt=0;
    rep(i,N){
        cin>>A[i];
        if(A[i]%4==0)cnt4++;
        else if(A[i]%2==0)cnt2++;
        else cnt ++;
    }
    if(cnt2==0 && cnt<=cnt4+1)cout<<"Yes"<<endl;
    else if(cnt2>0 && cnt<=cnt4)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}