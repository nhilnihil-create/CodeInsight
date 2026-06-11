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
    int ans=0,n;cin>>n;
    vector<int> vec(n);for(int i=0;i<n;i++){cin>>vec[i];vec[i]--;}
    for(int i=0;i<n;i++){
        if(vec[vec[i]]==i)ans++;
    }
    cout<<ans/2<<endl;
}
