#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define sp <<" "<<
#define cst(x) cout<<fixed<<setprecision(x)
#define pi 3.14159265359
#define mod 1000000007
using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using que_a = priority_queue<int, vector<int>, greater<int> >;
using que_d = priority_queue<int>;
using pint = pair<int,int>;

int main(){

    string s; cin >> s;
    vector<string> word = {"dream","dreamer","erase","eraser"};
    vector<bool> dp(100005,false);
    dp.at(0) = true;
    rep(i,s.size()){
        if(dp.at(i) == false) continue;
        for(auto wo : word){
            if(wo == s.substr(i,wo.size())) dp[i+wo.size()] = true;
        }
    }

    dp[s.size()] ? cyes : cno;
    return 0;   
}
