#include<bits/stdc++.h>
using namespace std;
#define INFTY 1<<20
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long int ll;
const int MOD=1000000007;

int main(){
    int h,w;cin>>h>>w;
    int n;cin>>n;
    vector<int> a(n);
    queue<int> clr;
    int c[h][w];
    rep(i,n){
        cin>>a[i];
        rep(j,a[i])clr.push(i+1);
    }
    
    rep(i,h){
        if(i%2==0){
            rep(j,w){
                int cl = clr.front();clr.pop();
                c[i][j] = cl;
            }
        }else{
            for(int j = w-1;j>=0;j--){
                int cl = clr.front();clr.pop();
                c[i][j] = cl;
            }
        }

    }
    rep(i,h){
        rep(j,w)cout<<c[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}