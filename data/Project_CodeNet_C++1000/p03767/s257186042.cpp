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
    int n,x;cin>>n;
    vector<int> vec(3*n);
    for(int i=0;i<3*n;i++){
        cin>>x;vec[i]=x;
    }
    lint ans=0;
    sort(all(vec),greater<int>());
    for(int i=1;i<2*n;i+=2){
        ans+=vec[i];
    }
    cout<<ans<<endl;
}
