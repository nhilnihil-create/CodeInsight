#include <iostream>
#include <queue>
#include <vector>
#include <stdint.h>
using namespace std;



int64_t h,w;
priority_queue< pair<int64_t,int64_t>,vector<pair<int64_t,int64_t>>,greater<pair<int64_t,int64_t>>> heap;
uint64_t ans=0;
int64_t oper[2];
int main()
{
    cin>>w>>h;
    oper[0]=w+1;
    oper[1]=h+1;
    for (int i=0;i<w;i++)
    {
     int64_t temp;
     cin>>temp;
     heap.push(make_pair(temp,0));
    }
    for (int i=0;i<h;i++)
    {
     int64_t temp;
     cin>>temp;
     heap.push(make_pair(temp,1));
    }
    while (!heap.empty())
    {
     auto f=heap.top();
     heap.pop();
     ans+=oper[1-f.second]*f.first;
     //cout<<f.first<<' '<<oper[1-f.second]<<' '<<oper[f.second]<<' '<<f.second<<' '<<ans<<endl;
     oper[f.second]--;
    // cout<<f.first<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
