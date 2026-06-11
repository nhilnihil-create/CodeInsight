#include <bits/stdc++.h>
using namespace std;
long long res;
string s;
void dfs(int l,long long sum,long long num) {
    if (l==(int)s.length()) {
        res+=num+sum;
        return;
    }
    dfs(l+1,sum*10+s[l]-'0',num);
    if (sum) dfs(l+1,s[l]-'0',num+sum);
}
int main()
{
    cin>>s;
    dfs(0,0,0);
    cout<<res<<endl;
    return 0;
}
