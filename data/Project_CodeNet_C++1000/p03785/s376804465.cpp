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
    int n,c,k,t,tlim,jokyaku,ans=0;cin>>n>>c>>k;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>t;vec[i]=t;
    }
    sort(all(vec));
    for(int i=0;i<n;i++){
        t=vec[i];
        if(i==0){
            tlim=t+k;
            jokyaku=1;
        }
        else{
            if(tlim<t){
                ans++;
                tlim=t+k;
                jokyaku=1;
            }
            else{
                if(jokyaku+1>c){
                    ans++;
                    tlim=t+k;
                    jokyaku=1;
                }
                else jokyaku++;
            }
        }
    }
    cout<<ans+1<<endl;
}
