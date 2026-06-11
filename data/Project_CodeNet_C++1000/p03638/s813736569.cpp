#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int h,w;cin>>h>>w;
    int n;cin>>n;
    queue<pair<int,int>> que;
    rep(i,n){
        int a;cin>>a;
        que.push({a,i+1});
    }
    que.push({100,1000});
    int t[h][w];
    int a=que.front().first,now=que.front().second;que.pop();
    
    rep(i,h){
        if(i%2==0){
            for(int j=0;j<w;j++){
                t[i][j]=now;a--;
                if(a==0){
                    a=que.front().first,now=que.front().second;que.pop();
                }
            }
        }else{
            for(int j=w-1;j>=0;j--){
                t[i][j]=now;a--;
                if(a==0){
                    a=que.front().first,now=que.front().second;que.pop();
                }
            }
        }
    }
    rep(i,h){
        rep(j,w)cout<<t[i][j]<<" ";
        cout<<endl;
    }
}