#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
using namespace std;
typedef long long ll;
int main(){
   #ifndef ONLINE_JUDGE 
      FILE_READ_IN 
      FILE_READ_OUT 
   #endif
    string s; cin>>s;
    int freq[26];
    fill(freq,freq+26,0);
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='a'&&s[i]<='z')
            freq[s[i]-'a']++;
    }
    bool ok=true;
    for(int i=0;i<26;i++)
    {
        if(freq[i]&1)
            ok=false;
    }
    if(ok)
        cout<<"Yes\n";
    else cout<<"No\n";
   return 0;
}