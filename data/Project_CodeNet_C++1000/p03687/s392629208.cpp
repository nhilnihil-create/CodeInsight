#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;

int main(){
    string s; cin >> s;
    int len = s.size();
    map<char,set<int>> m{};
    for(int i=0;i<s.size();i++) m[s[i]].insert(i);
    bool flag=true;
    int ans=0;
    while(flag){
        for(auto i:m){
            if(i.second.size()==len-ans) {flag=false; break;}
        }
        if(flag){
            ans++;
            for(auto i:m){
                for(auto j:i.second){
                    if(j-1>=0) m[i.first].insert(j-1);
                    if(j>len-ans-1) m[i.first].erase(j);
                }
            }
        }
    }
    cout << ans << endl;
}