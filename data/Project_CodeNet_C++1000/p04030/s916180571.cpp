#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
int main(){
    string s;
    cin >> s;
    stack<char> data;
    rep(i,0,s.size()){
        if(s[i]!='B'){
            data.push(s[i]);
        }else{
            if(data.empty()){
                continue;
            }else{
                data.pop();
            }
        }
    }
    stack<char> ans;
    while(!data.empty()){
        ans.push(data.top());
        data.pop();
        
    }
    while(!ans.empty()){
        cout<<ans.top();
        ans.pop();
    }
    cout<<endl;

  return 0;
}