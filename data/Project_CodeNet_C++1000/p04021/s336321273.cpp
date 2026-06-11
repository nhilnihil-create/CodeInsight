#include <bits/stdc++.h>
using namespace std;
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define scs(s) scanf("%s",s)
#ifndef GET_MACRO

#define GET_MACRO(__1,__2,__3,NAME,...) NAME

#endif // GET_MACRO

#define sci(...) GET_MACRO(__VA_ARGS__,sci3,sci2,sci1)(__VA_ARGS__)
#define ll long long
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define LSB(i) ((i)&(-i))
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
#define infl 0x7ffffffffffffff
#define infi  0x7fffffff
#define fill_(a,b) fill(a.begin(),a.end(),b)
#define pb push_back
#define xx first
#define yy second
int main(){
    int n,i;
    sci(n);
    vector<int> data(n);
    vector<int> sdata(n);
    for(i=0;i<n;i++){
        sci(data[i]);
        sdata[i]=data[i];
    }
    sort(sdata.begin(),sdata.end());
    map<int,int> map_;
    for(i=0;i<n;i++){
        map_[sdata[i]]=i+1;
    }
    int cnt=0;
    for(i=0;i<n;i++){
        data[i]=map_[data[i]];
        if((data[i]%2)!=(i+1)%2)cnt++;
    }
    cout<<cnt/2<<endl;
}
