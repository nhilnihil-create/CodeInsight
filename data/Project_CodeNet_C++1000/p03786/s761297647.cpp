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
    int n;cin>>n;
    vector<lint> vec(n);for(int i=0;i<n;i++)cin>>vec[i];
    sort(all(vec));
    vector<lint> ruiseki(1,0);
    for(int i=0;i<n;i++)ruiseki.pb(ruiseki[i]+vec[i]);
    int ans=1;
    for(int i=n-1;i>=0;i--){
        if(ruiseki[i]*2>=vec[i])ans++;
        else break;
    }
    cout<<ans<<endl;
}
