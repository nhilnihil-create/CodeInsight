#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cassert>
#include<complex>//real().imag().
#include<cctype>
#include<algorithm>
#include<iomanip>
#include<stack>
#include<queue>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<string>
#include<utility>
#include<iterator>
#define pii pair<int,int>
#define make_pair mp
using namespace std;
typedef long long ll;
int a[100005];
int main()
{
    // freopen("D:\\in.txt","r",stdin);
    // freopen("D:\\out.txt","w",stdout);
    //ios::sync_with_stdio(false);
    //system("pause");
    string s;
    cin>>s;
    int sum=0;
    for(int i=1;i<s.size()-1;i++)
    {
        if(s[i-1]!=s[i+1])sum++;
    }
    if(sum==0)
    {
        cout<<"Second"<<endl;
    }else
    if(s[0]!=s[s.size()-1])
    {
        if(s.size()%2==1)
        {
            cout<<"First"<<endl;
        }else
            cout<<"Second"<<endl;
    }else
    {
        if((s.size()-1)%2==1)
        {
            cout<<"First"<<endl;
        }else
            cout<<"Second"<<endl;
    }
    return 0;
}

