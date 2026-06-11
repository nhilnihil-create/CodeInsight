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
    int n,mod;cin>>n;
    lint x,y;
    vector<lint> a(n),b(n);
    for(int i=n-1;i>=0;i--)cin>>a[i]>>b[i];
    lint added=0;
    for(int i=0;i<n;i++){
        x=a[i]+added;y=b[i];
        mod=x%y;
        if(mod==0)mod=y;
        added+=(y-mod);
    }
    cout<<added<<endl;
}
