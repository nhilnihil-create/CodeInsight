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
    string s;cin>>s;
    int N=0,W=0,S=0,E=0;
    for(char c:s){
        if(c=='N')N++;
        else if(c=='W')W++;
        else if(c=='S')S++;
        else E++;
    }
    string ans="Yes";
    if((N==0&&S>0)||(N>0&&S==0))ans="No";
    if((E==0&&W>0)||(E>0&&W==0))ans="No";
    cout<<ans<<endl;
}
