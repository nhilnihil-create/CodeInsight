#include<iostream>
#include<deque>

using namespace std;
using ll = long long;


deque<int> ans1,ans2;

void solve(ll n,int& x){
    if(n==0)return ;
    if(n==1){
        ans1.push_front(x);ans2.push_front(x);
        ++x;
        return;
    }
    solve((n-1)/2,x);
    ans1.push_front(x);ans2.push_front(x);
    ++x;
    if(n%2==0){
        ans1.push_front(x);ans2.push_back(x);
        ++x;
    }
}
int main(){
    ll n;cin>>n;
    int x = 1;
    solve(n,x);
    cout<<ans1.size()+ans2.size()<<endl;
    for(auto e : ans1)cout<<e<<" ";
    for(auto e : ans2)cout<<e<<" ";
    return 0;
}