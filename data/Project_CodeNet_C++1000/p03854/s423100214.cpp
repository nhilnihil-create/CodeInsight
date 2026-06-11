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

vector<string> word = {"dream","dreamer","erase","eraser"};
string s;

bool dfs(int n){
    if(n == s.size()) return true;
    for(string wo : word){
        if(s.substr(n,wo.size()) == wo) if(dfs(n + wo.size())) return true;
    }
    return false;
}

int main(){

    cin >> s;
    dfs(0) ? cyes : cno;
    
    return 0;   
}
