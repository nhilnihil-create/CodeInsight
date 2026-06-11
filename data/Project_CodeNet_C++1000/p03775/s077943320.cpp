#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define str to_string
#define endl "\n"
#define PI 3.141592653589
using namespace std;
using lint = long long;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

int main(){
    int ans=100;
    lint n;cin>>n;
    for(int a=1;a<=sqrt(n);a++){
        if(n%a==0){
            int tmp=(str(n/a)).size();
            ans=min(tmp,ans);
        }
    }
    cout<<ans<<endl;
}
