//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define str to_string
#define endl "\n"
#define PI 3.141592653589
using namespace std;
using lint = long long;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

//AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC
int main(){
    int s,g;cin>>s>>g;
    int ans;
    if(s<=g){
        if((s>=0&&g>=0)||(s<=0&&g<=0))ans=g-s;
        else ans=max(abs(s),abs(g))-min(abs(s),abs(g))+1;
    }
    else{
        int tmp=max(abs(s),abs(g))-min(abs(s),abs(g));
        if((s>0&&g>0)||(s<0&&g<0))ans=tmp+2;
        else ans=tmp+1;
    }
    cout<<ans<<endl;
}
