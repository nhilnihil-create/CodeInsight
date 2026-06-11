#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int INF = 1e9;
 
int main(void){
    string s;
    cin>>s;
    map<char, priority_queue <int> > mp;
    rep(i, s.size()){
        mp[s[i]].push(i);
        if(mp[s[i]].size() == 1){
            mp[s[i]].push(-1);
            mp[s[i]].push(s.size());
        }
    }

    int ans = INF;
    for(auto p : mp){
        int tmp = 0;
        int bef = p.second.top();
        p.second.pop();
        while(!p.second.empty()){
            int now = p.second.top();
            p.second.pop();
            tmp=max(tmp, bef-now-1);
            bef=now;
        }
        //cout<<p.first<<" "<<tmp<<endl;
        ans=min(ans, tmp);
    }
    cout<<ans<<endl;
    return 0;
}