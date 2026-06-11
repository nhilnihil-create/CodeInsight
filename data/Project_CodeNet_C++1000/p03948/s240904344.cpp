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
int n,t;
int a[100005],pre[100005];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    // freopen("D:\\in.txt","r",stdin);
    // freopen("D:\\out.txt","w",stdout);
    //ios::sync_with_stdio(false);
    //system("pause");
    cin>>n>>t;
    int minn=10000000009;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        minn=min(a[i],minn);
        pre[i]=a[i]-minn;
    }
    sort(pre,pre+n,cmp);
    int cnt=1,idx=1;
    while(pre[idx]==pre[idx-1]&&idx<n)
    {
        cnt++;
        idx++;
    }
    cout<<cnt<<endl;
    return 0;
}

