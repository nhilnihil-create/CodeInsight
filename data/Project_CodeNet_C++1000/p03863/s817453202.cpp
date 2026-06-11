#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int main(){
    string s;
    cin>>s;
    bool win=(int)s.size()%2;
    win^=(s[0]==s.back());
    cout<<(win?"First":"Second")<<endl;
}
