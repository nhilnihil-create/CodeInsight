#include<bits/stdc++.h>
using namespace std;
long long s[200005];
set<long long>ss;
map<long long,int>m;
vector<long long>v;
int seg[800005];
void up(int st,int ed,int lv,int po)
{
    int md=(st+ed)/2;
    if(st>po || ed<po)
    return;
    if(st==po && ed==po)
    {
        seg[lv]++;
        return;
    }
    seg[lv]++;
    up(st,md,lv*2,po);
    up(md+1,ed,lv*2+1,po);
}
int sm(int st,int ed,int lv,int l,int r)
{
    int md=(st+ed)/2;
    if(st>r || ed<l)
    return 0;
    if(st>=l && ed<=r)
    return seg[lv];
    return sm(st,md,lv*2,l,r)+sm(md+1,ed,lv*2+1,l,r);
}
main()
{
	int t;
    long long req;
    scanf("%d%lld",&t,&req);
    for(int i = 1;i <= t;i++)
    {
        scanf("%lld",&s[i]);
        s[i]+=s[i-1]-req;
        ss.insert(s[i]);
    }
    int co=0;
    set<long long>::iterator sp;
    for(sp=ss.begin();sp!=ss.end();sp++)
    {
        m[*sp]=co;
        v.push_back(*sp);
        co++;
    }
    long long f=0;
    for(int i = 1;i <= t;i++)
    {
        if(s[i]>=0)
        f++;
        f+=sm(0,t,1,0,m[s[i]]);
        up(0,t,1,m[s[i]]);
    }
    printf("%lld",f);
}
