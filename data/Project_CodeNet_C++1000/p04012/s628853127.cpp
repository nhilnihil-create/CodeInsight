#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[26];
int main()
{
    string s;
    cin>>s;
    for(int i=0;s[i]!='\0';i++)
    {
        arr[s[i]-'a']++;
    }
    bool ans=true;
    for(int i=0;i<26;i++)
    {
        if(arr[i]%2)
        {
            ans=false;
            break;
        }
    }
    if(ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
