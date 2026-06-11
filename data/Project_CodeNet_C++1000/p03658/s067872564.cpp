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
    int n,k,x;cin>>n>>k;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>x;vec[i]=x;
    }
    sort(all(vec),greater<int>());
    int ans=0;
    for(int i=0;i<k;i++){
        ans+=vec[i];
    }
    cout<<ans<<endl;
}
