#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(bool x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb push_back;
#define sp " ";
#define unique 1000000007;
void vout(vector<int> v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
int main(){
    int n,m;
    lli ans,a=1,b=1; 
    cin>>n>>m;
    if(abs(n-m)>=2){
        ans=0;
    }
    else{
        rep(i,n){
            a*=(i+1);
            a=a%unique;
        }
        rep(i,m){
            b*=(i+1);
            b=b%unique;
        }
        if(abs(n-m)==1){
            ans=(a*b)%unique;
        }
        else{
            ans=(a*b)%unique;
            ans*=2;
        }
    }
    while(ans>=1000000007){
        ans=ans%unique;
    }
    cout<<ans;
}