#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t=1;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.size();
        map<int,int>cnt;
        for(int i=0; i<n; i++)
        {
            cnt[s[i]-'a']++;
        }
        bool flag=true;
        for(int i=0; i<26; i++)
        {
            if(cnt[i]%2==1)
            {
                flag=false;
                break;
            }
        }
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        cnt.clear();
    }
}
