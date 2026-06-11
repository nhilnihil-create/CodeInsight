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
    int K,s,ans=0;cin>>K>>s;
    for(int i=0;i<=K;i++){
        for(int j=0;j<=K;j++){
            int k=s-i-j;
            if(0<=k&&k<=K)ans++;
        }
    }
    cout<<ans<<endl;
}
