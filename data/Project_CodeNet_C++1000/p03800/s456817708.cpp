#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef long long ll;
typedef pair<ll,ll> pint;
ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}

int main(){
    ll n;cin>>n;
    string a;cin>>a;
    vector<vector<int> > res(4,vector<int>(n,0));
    int flag=-1;
    if(a[0]=='o'){
        res[0][0]=0;
        res[0][1]=0;
        res[0][n-1]=0;
        
        res[1][0]=0;
        res[1][1]=1;
        res[1][n-1]=1;
        
        res[2][0]=1;
        res[2][1]=1;
        res[2][n-1]=0;
        
        res[3][0]=1;
        res[3][1]=0;
        res[3][n-1]=1;
        
    }
    else{
        res[0][0]=0;
        res[0][1]=1;
        res[0][n-1]=0;
        
        res[1][0]=0;
        res[1][1]=0;
        res[1][n-1]=1;
        
        res[2][0]=1;
        res[2][1]=1;
        res[2][n-1]=1;
        
        res[3][0]=1;
        res[3][1]=0;
        res[3][n-1]=0;
    }
    rep(j,4)REP(i,1,n-1){
        if (-1<flag)continue;
        if(i!=n-2){
            if(a[i]=='o'&&res[j][i]==0){
                res[j][i+1]=res[j][i-1];
            }
            else if(a[i]=='o'&&res[j][i]==1){
                res[j][i+1]=(res[j][i-1]+1)%2;
            }
            else if(a[i]=='x'&&res[j][i]==0){
                res[j][i+1]=(res[j][i-1]+1)%2;
            }
            else if(a[i]=='x'&&res[j][i]==1){
                res[j][i+1]=res[j][i-1];
            }
        }
        else{
            if(a[i]=='o'&&res[j][i]==0){
                if(res[j][i+1]==res[j][i-1]){
                    flag=j;
                }
            }
            else if(a[i]=='o'&&res[j][i]==1){
                if(res[j][i+1]==(res[j][i-1]+1)%2){
                    flag=j;
                }
            }
            else if(a[i]=='x'&&res[j][i]==0){
                if(res[j][i+1]==(res[j][i-1]+1)%2){
                    flag=j;
                }
            }
            else if(a[i]=='x'&&res[j][i]==1){
                if(res[j][i+1]==res[j][i-1]){
                    flag=j;
                }
            }
        }
        if(-1<flag){
            if(res[j][n-1]==0){
                if(a[n-1]=='o'&&res[j][n-2]!=res[j][0]){
                    flag=-1;
                }
                else if(a[n-1]=='x'&&res[j][n-2]==res[j][0]){
                    flag=-1;
                }
            }
            else{
                if(a[n-1]=='o'&&res[j][n-2]==res[j][0]){
                    flag=-1;
                }
                else if(a[n-1]=='x'&&res[j][n-2]!=res[j][0]){
                    flag=-1;
                }
            }
        }
    }
    if(-1<flag){
    rep(k,n){
        if(res[flag][k]==0){
            cout<<'S';
        }
        else{
            cout<<'W';
        }
    }cout<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}