#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    string x;
    cin>>x;
    int n=x.size();

    int s=0,cnt=0;
    rep(i,n){
        if(x[i]=='S') s++;
        else{
            if(s>0){
                cnt++;
                s--;
            }
        }
    }

    cout<<n-2*cnt<<endl;
} 
