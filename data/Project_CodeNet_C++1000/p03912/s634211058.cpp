#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstdio>
#include<cmath>
using namespace std;
//#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
int MOD=1000000007;
int n,m;
int calc(vector<int> const& num,int s,int t,int r){
    int res=0;
    int sub=s-t;
    sub/=2;
    int buf=r;
    while(buf<=100000&&sub>0){
        int tmp=num[buf];
        if(tmp/2<sub){
            sub-=tmp/2;
            res+=tmp/2;
        }
        else{
            res+=sub;
            sub=0;
            break;
        }
        buf+=m;
    }
    return res;
}

signed main(){
    cin>>n>>m;
    vector<int> x(n);
    vector<int> rest(m+1,0);
    vector<int> num(100001,0);
    int res=0;
    rep(i,n){
        cin>>x[i];
        rest[x[i]%m]++;
        num[x[i]]++;
    }
    //sort(ALL(rest));
    res+=rest[0]/2;
    int hulf=m/2;
    rep1(i,hulf){
        int flag=3;
        //cout<<res<<endl;
        if(rest[i]==rest[m-i]){
            if(m%2==0&&i==hulf){
                res+=rest[i]/2;
            }
            else{
                flag=2;
                res+=rest[i];
            }
        }
        else if(rest[i]<=rest[m-i]){
            flag=1;
            res+=rest[i];
            res+=calc(num,rest[m-i],rest[i],m-i);
        }
        else{
            res+=rest[m-i];
            res+=calc(num,rest[i],rest[m-i],i);
        }
        //cout<<flag<<endl;
    }
    cout<<res<<endl;
    return 0;
}