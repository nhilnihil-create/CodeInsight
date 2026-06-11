#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int n;
    cin>>n;
    int s=n*n;//ans size
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    vector<tuple<int,int,int>>f(n),b(n);//queries
    rep(i,n){//answer 0-indexed
        get<0>(f[i])=a[i]-2;
        get<1>(f[i])=i;
        get<2>(f[i])=i+1;
        get<0>(b[i])=a[i];
        get<1>(b[i])=n-i-1;
        get<2>(b[i])=i+1;
    }
    vector<int>ans(s);
    rep(i,n)ans[a[i]-1]=i+1;
    //rep(i,s)cout<<ans[i];
    sort(all(f));
    sort(all(b),greater<tuple<int,int,int>>());
    //前後それぞれの条件を用意したので厳しいものから満たしていく
    int g,c,k;//goal,cap,number
    rep(i,n){
        g=get<1>(f[i]);
        c=get<0>(f[i]);
        k=get<2>(f[i]);
        //cout<<c<<g<<k<<endl;
        for(int j=0;j<=c;j++){
            if(g){
                if(ans[j]==0){
                    ans[j]=k;
                    g--;
                }
            }
            else break;
        }
        if(g){
            cout<<"No";
            return 0;
        }
    }
    rep(i,n){
        g=get<1>(b[i]);
        c=get<0>(b[i]);
        k=get<2>(b[i]);
        //cout<<c<<g<<k<<endl;
        for(int j=s-1;j>=c;j--){
            if(g){
                if(ans[j]==0){
                    ans[j]=k;
                    g--;
                }
            }
            else break;
        }
        if(g){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    rep(i,s)cout<<ans[i]<<' ';
	return 0;
}
