#include <bits/stdc++.h>

using namespace std;
vector<long long>v;
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

bool comp(pair<int,int>a,pair<int,int>b){
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}

unordered_map<pair<int,int>,int, hash_pair>vis;
vector<pair<int,int> >vps;
long long n,h,w;
int cnt(int dlx,int dly,int urx,int ury,pair<int,int>center){

    if(urx>h||dlx<1||ury>w||dly<1)
        return 0;
    int cntb=0;
    for(int x=dlx;x<=urx;x++){
        for(int y=dly;y<=ury;y++){
            if(*(lower_bound(vps.begin(),vps.end(),make_pair(x,y),comp))==make_pair(x,y)){
                if(x<center.first)
                    return 0;
                if(x==center.first&&y<center.second)
                    return 0;
                cntb++;
            }
        }
    }
    return cntb;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);      cout.tie(0);
    v.resize(10);
    cin>>h>>w>>n;
    vps.resize(n);
    for(int i=0;i<n;i++){
        cin>>vps[i].first>>vps[i].second;
    }
    sort(vps.begin(),vps.end(),comp);
    for(int i=0;i<n;i++){
        for(int x=-2;x<=0;x++){
            for(int y=-2;y<=0;y++){
                v[cnt(vps[i].first+x,vps[i].second+y,vps[i].first+x+2,vps[i].second+y+2,vps[i])]++;
                ///cout << vps[i].first+x << ' '<< vps[i].second+y << ' '<< vps[i].first << ' '<< vps[i].second<< ' '<< cnt(vps[i].first+x,vps[i].second+y,vps[i].first+x+2,vps[i].second+y+2,vps[i]) << '\n';
            }
        }
    }
    int cnttl=0;
    for(int i=1;i<10;i++){
        cnttl+=v[i];
    }
    v[0]=(h-2)*(w-2)-cnttl;
    for(int i=0;i<10;i++)
        cout << v[i] << '\n';
    return 0;
}
/**
4 5 8
1 1
1 4
1 5
2 3
3 1
3 2
3 4
4 4
*/
