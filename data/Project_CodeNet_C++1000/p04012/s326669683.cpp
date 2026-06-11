#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int cnt[27];
    for(int i=0; i<27; i++) cnt[i]=0;
    int i=0;
    while(s[i]!='\0')
    {
        cnt[s[i]-'a']++;
        i++;
    }
    int c= 1;
    for(i=0; i<27; i++)
    { //cout<<cnt[i]<<" ";
        if(cnt[i]>0)
        {
            if(cnt[i]%2==0) c=1;
            else {c=0; break;}
        }
    }
    if(c==1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
