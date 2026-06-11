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
    int a,b;cin>>a>>b;
    string ans;
    if(a>0){
        ans="Positive";
    }
    else if(a==0){
        ans="Zero";
    }
    else{
        if(b>=0)ans="Zero";
        else{
            int kosuu=b-a+1;
            if(kosuu%2==1)ans="Negative";
            else ans="Positive";
        }
    }
    cout<<ans<<endl;
}
