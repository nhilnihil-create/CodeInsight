#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

const int maxn = 2e5+7;
const int mod  = 1e9+7;
const int inf  = 2e9;

int get_len()
{
    string test="1";
    string ans;
    cout<<"? "<<test<<endl;
    while(cin>>ans,ans=="Y")
    {
        if(test.length()>10) return -1;
        test+='0';
        cout<<"? "<<test<<endl;
    }
    return test.length()-1;
}

int main()
{
#ifdef LOCAL
    freopen("sample.in","r",stdin);
#endif
    //ios::sync_with_stdio(false);
    int len=get_len();
    string ans="";
    string re;
    if(len==-1)
    {
        ans="2";
        cout<<"? "<<ans<<endl;
        cin>>re;
        if(re=="Y")
        {
            cout<<"! "<<1<<endl;
            return 0;
        }
        ans="1";
        for(int i=0;i<=10;i++)
        {
            string temp=ans;
            temp+='1';
            cout<<"? "<<temp<<endl;
            cin>>re;
            if(re=="Y")
            {
                cout<<"! "<<ans<<'0'<<endl;
                return 0;
            }
            ans+='0';
        }
    }
    if(len==1)
    {
        ans+="19";
        for(int i=1;i<=9;i++)
    {
        ans[len-1]=(i+'0');
        cout<<"? "<<ans<<endl;
        cin>>re;
        if(re=="Y")
        {
            ans[len]='\0';
            cout<<"! "<<ans<<endl;
            return 0;
        }
    }
    }
    for(int i=1;i<len;i++)
    {
        int l=0,r=9;
        int mid;
        while(l<r)
        {
           string temp=ans;
           mid=(l+r)/2+1;
           temp+=(mid+'0');
           cout<<"? "<<temp<<endl;
           cin>>re;
           if(re=="Y")
               l=mid;
           else 
               r=mid-1;
        }
        ans+=(l+'0');
    }
    ans+="09";
    for(int i=0;i<=9;i++)
    {
        ans[len-1]=(i+'0');
        cout<<"? "<<ans<<endl;
        cin>>re;
        if(re=="Y")
        {
            ans[len]='\0';
            cout<<"! "<<ans<<endl;
            return 0;
        }
    }
    return 0;
}


