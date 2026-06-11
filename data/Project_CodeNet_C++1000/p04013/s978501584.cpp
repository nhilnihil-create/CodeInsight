#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ii pair<int ,int >
#define S second
#define F first
#define PI 3.1415926535897932384626
#define SPEED std::ios_base::sync_with_stdio(false);

ll n,A,a[55],mem[55][55][2550];

ll dp(int i,int j,int sum){
    if(i==n){
        if(j>0 && sum%j==0 && sum==j*A) return 1LL;
        return 0LL;
    }
    ll &ret = mem[i][j][sum];
    if(ret!=-1)return ret;

    ll p1,p2;
    p1 = dp(i+1,j+1,sum+a[i]);
    p2 = dp(i+1,j,sum);

    return ret = p1+p2;
}

int main(){
    SPEED
    cin>>n>>A;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    memset(mem,-1,sizeof mem);
    cout<<dp(0,0,0);

}
