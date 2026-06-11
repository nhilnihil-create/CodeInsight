#pragma GCC optimize("O2")
#include<bits/stdc++.h>
 
#define int long long int
#define endl "\n"
#define mod 100000000
 
using namespace std;
 
typedef double DB;
 
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}
 
bool findix(string s,string t)
{
    int j=0;
    for(int i=0;i<s.length();++i)
    {
        if(j==t.length()) return false;
        while(s[i]!=t[j])
        {
            if(j==t.length()-1) return false; 
            ++j;
        }
    }
    return true;
}
 
int maxim(string s)
{
    int maxi=INT_MIN;
    for(int i=0;i<s.length();++i) maxi=max(maxi,1LL*(s[i]-'0'));
    return maxi;
}
 
int minim(string s)
{
    int mini=INT_MAX;
    for(int i=0;i<s.length();++i) mini=min(mini,1LL*(s[i]-'0'));
    return mini;
}
 
signed main()
{
    fastio();
    string s; cin>>s; int arr[26]={0};
    for(int i=0;i<s.length();++i) {++arr[s[i]-'a'];}
    for(int i=0;i<26;++i) 
    {
        if(arr[i]>1) {cout<<"no"; return 0;}
    }
    cout<<"yes"; 
    return 0;
}