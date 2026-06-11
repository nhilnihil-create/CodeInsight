#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

bool ch(string s){
    unordered_set<char>q;
    for (int i = 0; i <(int)s.size(); ++i) {
        q.insert(s[i]);
    }
    if(q.size()==1)return true;
    else return false;
}

int main(){
    string s;cin >>s;
    ll ans=INF;
    string c=s;
    int n=s.size();
    for (int i = 0; i <n; ++i) {
        c=s;
        string b;
        char key=s[i];
        ll now=0;
        while(!ch(c)){
            for (int j = 0; j < c.size() - 1; ++j) {
                if(c[j]==key||c[j+1]==key){
                    b.push_back(key);
                }
                else b.push_back(c[j]);
            }
            c=b;
            b="";
            now++;
        }
        ans=min(ans,now);
    }
    cout <<ans <<endl;
}
