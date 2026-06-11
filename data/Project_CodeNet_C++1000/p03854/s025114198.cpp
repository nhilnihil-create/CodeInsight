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
    string s,ans="YES";cin>>s;
    int sz=s.size();
    reverse(all(s));
    int p=0;
    while(true){
        if(p>=sz)break;
        if(s.substr(p,5)=="maerd")p+=5;
        else if(s.substr(p,5)=="esare")p+=5;
        else if(s.substr(p,6)=="resare")p+=6;
        else if(s.substr(p,7)=="remaerd")p+=7;
        else {ans="NO";break;}
    }
    cout<<ans<<endl;
}
