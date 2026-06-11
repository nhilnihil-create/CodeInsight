#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
    int n;
    cin>>n;
    map<int,int> A;
    rep(i,n){
        int a;
        cin>>a;
        A[a-1]++;
    }
    //書かれた数字はいらないので、枚数の情報のみ大きい順に取り出したい
    priority_queue<int,vector<int>,less<int>> que;
    for(auto m:A) que.push(m.second);
    int ans=0;
    while(!que.empty()){
        int v=que.top();
        if(v==1) break;//一番多い枚数が1ならおわり
        que.pop();
        while(v>=3){//a,a,aのように取り出せたら1回の操作で2枚削る
            ans++;
            v-=2;
        }
        if(v==2){//a,a,bのように取り出せば、a,bの大小にかかわらず操作後aが残る
            int w=que.top();
            que.pop();
            if(w>1) que.push(w-1);
            v--;
        }
        que.push(v);
    }
    cout<<que.size()<<endl;
    return 0;
}