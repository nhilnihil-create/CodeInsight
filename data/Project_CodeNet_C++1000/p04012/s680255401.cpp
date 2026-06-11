#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
#define sf(x) scanf("%d",&x)
#define sfl(x) scanf("%lld",&x)
#define lli long long int
#define ll64 int64_t
#define pb push_back
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define frr(i,a) for(int i=0;i<a;i++)
#define frl(i,a) for(lli i=0;i<a;i++)
int main()
{
    string s;
    cin>>s;
    map<char,lli>frec;
    bool ans=true;
    for(lli i=0;i<s.size();i++)
    {
        frec[s[i]]++;
    }
    for(char a='a';a<='z';a++)
    {
        if(frec[a]%2!=0)
        {
            ans=false;
        }
    }
    if(ans)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
}
