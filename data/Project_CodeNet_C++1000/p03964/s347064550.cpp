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
    int n;cin>>n;
    lint a=1,b=1,x,y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        lint at=(a+x-1)/x,bt=(b+y-1)/y;
        if(at>bt){
            a=at*x;
            b=at*y;
        }
        else{
            a=bt*x;
            b=bt*y;
        }
    }
    cout<<a+b<<endl;
}
