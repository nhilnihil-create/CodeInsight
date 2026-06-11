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
    int n,a;cin>>n;
    vector<int> vec(100010);
    for(int i=0;i<n;i++){
        cin>>a;vec[a]++;
    }
    int ans=0,tmp;
    for(int i=1;i<100000;i++){
        tmp=vec[i-1]+vec[i]+vec[i+1];
        if(tmp>ans)ans=tmp;
    }
    cout<<ans<<endl;
}
