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
    vector<int> vec(26);
    string s;cin>>s;
    for(char c:s)vec[c-'a']++;
    string ans="None";
    for(int i=0;i<26;i++){
        if(vec[i]==0){ans=char('a'+i);break;}
    }
    cout<<ans<<endl;
}
