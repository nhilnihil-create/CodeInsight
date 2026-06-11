#include<cmath>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<functional>
#define INF 1e16
#define N (998244353)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,P> Q;





int main(void){
    int h,w;
    cin>>w>>h;
    priority_queue<ll,vector<ll>,greater<ll>>p,q;
    for(int i=0;i<w;i++){
        ll x;
        cin>>x;
        q.push(x);
    }
    for(int i=0;i<h;i++){
        ll x;
        cin>>x;
        p.push(x);
    }
    ll ans = 0;
    ll tate = 0,yoko = 0;
    while((!p.empty())&&(!q.empty())){
        ll pprev = p.top();
        ll qprev = q.top();
        if(pprev>=qprev){
            ans+=qprev*(h+1-tate);
            yoko++;
            q.pop();
        }
        else{
            ans+=pprev*(w+1-yoko);
            tate++;
            p.pop();
        }
        //cout<<ans<<endl;
    }
    if(q.empty()&&p.empty())cout<<ans<<endl;
    else{
        if(q.empty()){
            while(!p.empty()){
                ans+=p.top();
                p.pop();
            }
            cout<<ans<<endl;
        }
        else{
            while(!q.empty()){
                ans+=q.top();
                q.pop();
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}