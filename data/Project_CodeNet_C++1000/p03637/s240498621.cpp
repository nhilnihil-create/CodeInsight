#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    int N;cin>>N;
    int fmul=0;
    int tmul=0;
    int nomul=0;
    vector<int>a(N);
    rep(i,N){
        cin>>a.at(i);
        if(a.at(i)%4==0)fmul++;
        else if(a.at(i)%2==0)tmul++;
    }
    nomul=N-fmul-tmul;
    if(2*fmul+1>=N){
        cout<<"Yes"<<endl;
        return 0;
    }else if(fmul>=nomul){
        cout<<"Yes"<<endl;
        return 0;
    }else{
        cout<<"No"<<endl;
        return 0;
    }





}