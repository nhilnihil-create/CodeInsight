#define _GLIBCXX_DEBUG
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
    int k,t;cin>>k>>t;
    vector<int> vec(t);
    if(t==1){cin>>k;cout<<k-1<<endl;return 0;}
    for(int i=0;i<t;i++)cin>>vec[i];
    sort(all(vec),greater<int>());
    int ans;
    if(vec[0]==vec[1])ans=0;
    else{
        int tmp=0;
        for(int i=1;i<t;i++)tmp+=vec[i];
        if(tmp<vec[0])ans=vec[0]-tmp-1;
        else ans=0;
    }
    cout<<ans<<endl;
}
