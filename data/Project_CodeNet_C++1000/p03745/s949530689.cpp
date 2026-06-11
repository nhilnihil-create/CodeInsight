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
    int n,ans=1;cin>>n;
    int rem,check=-1,x;
    for(int i=0;i<n;i++){
        cin>>x;
        if(check==-1){rem=x;check=0;}
        else if(check==0){
            if(rem==x)continue;
            else if(rem>x){rem=x;check=-2;}
            else {rem=x;check=1;}
        }
        else if(check==-2){
            if(rem==x)continue;
            else if(rem>x){
                rem=x;
            }
            else {
                ans++;
                rem=x;
                check=0;
            }
        }
        else{
            if(rem==x)continue;
            else if(rem<x){
                rem=x;
            }
            else{
                ans++;
                rem=x;
                check=0;
            }
        }
    }
    cout<<ans<<endl;
}
