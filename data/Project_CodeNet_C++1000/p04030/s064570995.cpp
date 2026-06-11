#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define fi first
#define sec second
#define PB push_back
#define MP make_pair
#define endl '\n'
#define rep(i,a,b)      for(int i=a;i<=b;i++)
#define revp(i,a,b)     for(int i=b;i>=a;i--)
#define all(v)          v.begin(),v.end()
void fast(){ ios::sync_with_stdio(false); cin.tie(NULL);}
void file()
{ 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);
    #endif
}

string s;
string ans="";

int main()
{
    fast();
    

    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='B')
        {
            if(!ans.empty())
                ans.pop_back();
        }
        else
            ans.push_back(s[i]);
    }
    cout<<ans;
}
