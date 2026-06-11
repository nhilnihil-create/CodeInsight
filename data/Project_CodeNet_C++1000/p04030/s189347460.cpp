#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    string s;
    cin>>s;
    
    int n=s.size();
    deque<char> dq;
    rep(i,n){
        if(s[i]=='0') dq.push_back('0');
        else if(s[i]=='1') dq.push_back('1');
        else{
            if(dq.empty()) continue;
            dq.pop_back();
        }
    }

    while(!dq.empty()){
        cout<<dq.front();
        dq.pop_front();
    }
    cout<<endl;
}

