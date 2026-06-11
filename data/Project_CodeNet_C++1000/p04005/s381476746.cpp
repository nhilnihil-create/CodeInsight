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
    lint a,b,c;cin>>a>>b>>c;
    lint ans;
    if(a%2==0||b%2==0||c%2==0)ans=0;
    else{
        if(a>b&&a>c)ans=b*c;
        else if(b>c)ans=a*c;
        else ans=a*b;
    }
    cout<<ans<<endl;
}

