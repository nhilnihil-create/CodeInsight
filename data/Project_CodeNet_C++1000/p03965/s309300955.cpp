#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=2e5+100;
typedef pair<int,int>pa;
map<pa,int>mp;
ll ans[10];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    string s;
    cin>>s;
    int win=0,lose=0;
    int g=0,p=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='g'){
            if(p<g) p++,win++;
            else g++;
        }
        else {
            if(p<g) p++;
            else g++,lose++;
        }
    }
    cout<<win-lose<<endl;
    return 0;
}
