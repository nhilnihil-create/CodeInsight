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
    lint ans1=0,ans2=0;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>a;vec[i]=a;
    }
    int tmp=0;
    for(int i=0;i<n;i++){
        tmp+=vec[i];
        if(i%2==0){
            if(tmp<=0){
                ans1+=(1-tmp);
                tmp=1;
            }
        }
        else{
            if(tmp>=0){
                ans1+=(1+tmp);
                tmp=-1;
            }
        }
    }
    tmp=0;
    for(int i=0;i<n;i++){
        tmp+=vec[i];
        if(i%2==1){
            if(tmp<=0){
                ans2+=(1-tmp);
                tmp=1;
            }
        }
        else{
            if(tmp>=0){
                ans2+=(1+tmp);
                tmp=-1;
            }
        }
    }
    cout<<min(ans1,ans2)<<endl;
}
