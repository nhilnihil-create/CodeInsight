//递归
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000
typedef long long ll;
string s;
ll sum;
void dfs(vector<bool> b){
    if(b.size()==s.size()-1){
        ll tmp=0;
        // for(int i=0;i<b.size();++i)cout<<b[i];cout<<endl;
        for(int i=0;i<s.size();++i){
            tmp=tmp*10+s[i]-'0';
            if(i!=s.size()-1&&b[i]){/*cout<<tmp<<endl;*/sum+=tmp;tmp=0;}
        }
        sum+=tmp;
        return;
    }
    b.push_back(0);
    dfs(b);
    b.pop_back();
    b.push_back(1);
    dfs(b);
}
int main(){
    cin>>s;
    vector<bool> b;
    dfs(b);
    cout<<sum<<endl;
    return 0;
}
