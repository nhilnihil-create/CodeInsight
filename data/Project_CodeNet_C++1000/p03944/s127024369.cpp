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
    int w,h,n,x,y,a;cin>>w>>h>>n;
    vector<vector<int>> vec(h,vector<int>(w,0));
    for(int i=0;i<n;i++){
        cin>>x>>y>>a;
        if(a==1){
            for(int j=0;j<h;j++){
                for(int k=0;k<x;k++){
                    vec[j][k]=1;
                }
            }
        }
        else if(a==2){
            for(int j=0;j<h;j++){
                for(int k=x;k<w;k++){
                    vec[j][k]=1;
                }
            }
        }
        else if(a==3){
            for(int j=0;j<y;j++){
                for(int k=0;k<w;k++){
                    vec[j][k]=1;
                }
            }
        }
        else{
            for(int j=y;j<h;j++){
                for(int k=0;k<w;k++){
                    vec[j][k]=i;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(vec[i][j]==0)ans++;
        }
    }
    cout<<ans<<endl;
}
