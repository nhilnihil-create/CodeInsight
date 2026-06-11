#include <iostream>
#include <deque>
using namespace std;
long long n;
int i;
deque<int> solve(long long n)
{
    deque<int> ret;
    if(n==1) return ret;
    if(n%2)
    {
        ret=solve(n-1);
        ret.push_front(ret.size()+1);
    }
    else
    {
        ret=solve(n/2);
        ret.push_back(ret.size()+1);
    }
    return ret;
}
int main()
{
    cin>>n;n++;
    deque<int> ans=solve(n);
    int cate=ans.size();
    for(i=1;i<=cate;i++)
        ans.push_back(i);
    cout<<ans.size()<<'\n';
    for(i=0;i<ans.size();i++)
        cout<<ans[i]<<' ';
    return 0;
}
