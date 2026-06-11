#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string S;
    cin>>S;
    int N = S.size();
    int cnt = 0;
    stack<int> memo;
  	memo.push(N);
    vector<bool> check(26);
    for(int i = N-1; i >= 0; i--){
        int t = S[i]-'a';
        if(!check[t]){
            cnt++;
            check[t]=true;
        }
        if(cnt == 26){
            for(int j = 0; j < 26; j++) check[j]=false;
            cnt=0;
            memo.push(i);
        }
    }
    int p = 0;
    vector<char> ans;
    while(!memo.empty()){
        int t = memo.top();
        memo.pop();
        vector<bool> alph(26,false);
        for(int i = p; i < t; i++){
            int s = S[i]-'a';
            alph[s]=true;
        }
        for(int i = 0; i < 26; i++){
            if(!alph[i]){
                char c = 'a'+i;
                ans.push_back(c);
                break;
            }
        }
        while(true&&t<N){
            if(S[t]==*ans.rbegin()){
                p=t+1;
                break;
            }
            t++;
        }
    }
    for(auto x:ans) cout<<x;
    cout<<endl;
}