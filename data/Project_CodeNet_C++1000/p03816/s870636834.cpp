#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    priority_queue<pair<int,int> >pq;
    set<int>s;
    map<int,int>mp;
    vector<int>v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        mp[a]++;
        s.insert(a);
        v.push_back(a);
    }

    for(auto it:s){
        pq.push({mp[it],it});
    }
    while(!pq.empty()){
        int cur=pq.top().first;
        int val=pq.top().second;
        if(cur==1)
            break;
       // cout<<cur<<" "<<val<<endl;
        pq.pop();
        if(cur>=3){
            mp[val]-=3;
            mp[val]++;
            pq.push({mp[val],val});
        }
        else if(cur==2){
            mp[val]--;
            pq.push({mp[val],val});
            cur=pq.top().first;
            val=pq.top().second;
            mp[val]--;
            pq.pop();
            if(mp[val])
            pq.push({mp[val],val});
        }
    }
    cout<<pq.size()<<endl;
    return 0;
}
