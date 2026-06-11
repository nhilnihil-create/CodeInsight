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
    int a,b,c,a2,b2,c2,ans=0;cin>>a>>b>>c;
    if(a==b&&b==c&&a%2==0)ans=-1;
    else{
        while(a%2==0&&b%2==0&&c%2==0){
            ans++;
            a2=b/2+c/2;
            b2=a/2+c/2;
            c2=a/2+b/2;
            a=a2;b=b2;c=c2;
        }
    }
    cout<<ans<<endl;
}
