#include <bits/stdc++.h>
using namespace std;

#define pb(s) push_back(s)
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PI 3.14159265358979323846264338327950L


typedef long long ll;

const ll MOD =1e9+7;

vector<string> vis;

void dfs(string str){
    vis.push_back(str);
    string temp=str;
    for(int i=1;i<str.size();++i){
        if(str[i]!='+'&&str[i-1]!='+'){
            str.insert(i,1,'+');
        }
        if(find(ALL(vis),str)==vis.end()) dfs(str);
        str=temp;
    }
}

ll calc(string str){
    string temp="";
    ll sum=0;
    for(int i=0;i<str.size();++i){
        if(str[i]=='+'){
            sum+=stoll(temp);
            temp="";
            continue;
        }
        else{
            temp+=str[i];
        }
    }
    sum+=stoll(temp);
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin>>str;
    dfs(str);
    ll sum=0;
    for(auto u:vis){
        sum+=calc(u);
    }
    cout<<sum;
    return 0;
}
