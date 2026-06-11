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
    int n,m,x,y;cin>>n>>m;
    vector<int> balls(n,1);
    vector<bool> red(n,false);red[0]=true;
    for(int i=0;i<m;i++){
        cin>>x>>y;x--;y--;
        balls[x]--;
        balls[y]++;
        if(red[x]){
            red[y]=true;
            if(balls[x]==0)red[x]=false;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(red[i])ans++;
    }
    cout<<ans<<endl;
}
