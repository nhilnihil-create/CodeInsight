#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
const int inf=0x3f3f3f3f;
int a[100005];
int main()
{
    ios::sync_with_stdio(false);
    string s; cin>>s;
    int len=s.size();
    if(s[0]==s[s.size()-1]) len--;
    if(len%2==0)
        cout<<"Second"<<endl;
    else
        cout<<"First"<<endl;
    return 0;
}
