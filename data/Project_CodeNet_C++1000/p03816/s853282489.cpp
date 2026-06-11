#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>
#include <set>
#include <list>

using namespace std;
typedef long long ll;
#define rep(i, s, e) for (int(i) = (s); (i) <= (e); ++(i))
#define all(x) x.begin(),x.end()


int main()
{
    int n;cin>>n;
    map<int,int> mp;
    rep(i,1,n){
        int a;cin>>a;
        ++mp[a];
    }
    int cnt = 0;
    for(auto x:mp){
        if(x.second%2==0)++cnt;
    }
    if(cnt%2)cout<<mp.size()-1<<endl;
    else cout<<mp.size()<<endl;
}
