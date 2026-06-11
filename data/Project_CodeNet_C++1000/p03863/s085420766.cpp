#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int>pa;

const int N=2e5+100;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    string s;cin>>s;
    int len=s.size();
    if(s[0]==s[len-1]) len--;
    if(len%2==0) puts("Second");
    else puts("First");
    return 0;
}

