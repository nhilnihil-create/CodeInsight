#include <iostream>
#include <queue>
#include <vector>
#include <cstdint>
#include <algorithm>
using namespace std;

#define LL int64_t

LL h,w;
vector<pair<LL,LL>> heap;
unsigned long long ans=0;
LL oper[2];
int main()
{
    cin>>w>>h;
    oper[0]=w+1;
    oper[1]=h+1;
    for (int i=0;i<w;i++)
    {
     LL temp;
     cin>>temp;
     heap.push_back(make_pair(temp,0));
    }
    for (int i=0;i<h;i++)
    {
     LL temp;
     cin>>temp;
     heap.push_back(make_pair(temp,1));
    }
    //while (!heap.empty())
    sort(heap.begin(),heap.end());
    for (auto f:heap)
    {
    // auto f=heap.top();
     //heap.pop();
     ans+=oper[1-f.second]*f.first;
     //cout<<f.first<<' '<<oper[1-f.second]<<' '<<oper[f.second]<<' '<<f.second<<' '<<ans<<endl;
     oper[f.second]--;
    // cout<<f.first<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
