#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int k, t;
    cin>>k>>t;
    vector<int>v(t);
    priority_queue<pair<int, int> > que;
    rep(i, t) {
        int a;
        cin>>a;
        que.push(make_pair(a, i));
    }
    int bef = -1;
    int ans = 0;
    while(!que.empty()){
        pair<int, int> p = que.top();
        que.pop();
        if(p.second != bef){
            bef = p.second;
            p.first --;
            if(p.first>0) que.push(make_pair(p.first, p.second));
        }
        else{
            if(que.size() == 0){
                ans++;
                p.first--;
                bef = p.second;
                if(p.first>0) que.push(make_pair(p.first, p.second));
            }
            else{
                auto u = que.top();
                bef = u.second;
                que.pop();
                u.first--;
                if(u.first>0) que.push(make_pair(u.first, u.second));
                que.push(p);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}