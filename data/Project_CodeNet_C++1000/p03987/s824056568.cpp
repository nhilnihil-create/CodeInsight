#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int maxn = 2e5+10;
struct node{
    ll pre,net,num;
};
stack<node>sp;
ll s[maxn],ans=0;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    node fr,to;
    fr.net=fr.pre=1;fr.num=s[1];sp.push(fr);
    for(int i=2;i<=n;i++){
        to.num=s[i];
        to.pre=to.net=1;
        while(!sp.empty()&&to.num<=sp.top().num){
            fr=sp.top();sp.pop();
            if(!sp.empty()) sp.top().net+=fr.net;
            to.pre+=fr.pre;
            ans+=fr.pre*fr.num*fr.net;
        }
        sp.push(to);
    }
    while(!sp.empty()){
        fr=sp.top();sp.pop();
        if(!sp.empty()) sp.top().net+=fr.net;
        ans+=fr.pre*fr.num*fr.net;
    }
    cout<<ans<<endl;
    return 0;
}