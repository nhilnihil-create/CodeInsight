


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
int mod(ll a){return a%1000000007;};
typedef pair<int,int> i_i;

ll abss(ll a){
    if(a>0)return a;
    else return a*(-1);
}

int main(){
    int n;cin>>n;
    ll sum[n];for(int i=0;i<=n-1;i++)sum[i]=0;
    ll su=0;
    for(int i=0;i<=n-1;i++){
        int x;cin>>x;
        su+=x;
        sum[i]=su;
    }
    ll min=(ll)200000*1000000000;
    for(int i=0;i<=n-2;i++){
        if(abs(sum[i]*2-su)<min)min=abs(sum[i]*2-su);
    }
    cout<<min<<endl;
    return 0;
}
