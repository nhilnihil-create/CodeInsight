#include<math.h>
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ll long long int
#define py printf("Yes\n")
#define pn printf("No\n")
#define in cin>>
using namespace std;
int INF = 1001001001;

int main()
{
    string s;
    in s;
    bool flag=true;

    for(int i=0;i<s.size();i++)
    {
        for(int j=i+1;j<s.size();j++)
        {
            if(s[i]==s[j])flag=false;
        }
    }
    if(flag==true)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}
