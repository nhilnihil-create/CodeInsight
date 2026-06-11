//#define _GLIBCXX_DEBUG
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
    string s;cin>>s;
    char rem1=s[0],rem2=s[1];
    if(rem1==rem2){
        cout<<1<<" "<<2<<endl;
        return 0;
    }
    for(int i=2;i<s.size();i++){
        if(rem1==s[i]){
            cout<<i-1<<" "<<i+1<<endl;return 0;
        }
        if(rem2==s[i]){
            cout<<i<<" "<<i+1<<endl;return 0;
        }
        rem1=rem2;rem2=s[i];
    }
    cout<<-1<<" "<<-1<<endl;
}
