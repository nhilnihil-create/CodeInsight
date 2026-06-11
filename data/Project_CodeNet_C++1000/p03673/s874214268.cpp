#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    deque<int>q;
    rep(i,n){
        int a; cin>>a;
        if(n%2==i%2)q.push_back(a);
        else q.push_front(a);
    }
    while(!q.empty()){
        if(q.size()!=1)cout<<q.front()<<" ";
        else cout<<q.front()<<endl;
        q.pop_front();
    }
}