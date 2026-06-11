#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
void fast()
{
ios::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
}
int main()
{
    char s[105];
    int a[28]={0};
    cin>>s;
    for(int i=0;i<strlen(s);i++)
    {
        int temp=(int)s[i]-'a';
        a[temp]++;
    }
    for(int i=0;i<27;i++)
    {
        if(a[i]%2)
        {
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"Yes\n"<<endl;
}