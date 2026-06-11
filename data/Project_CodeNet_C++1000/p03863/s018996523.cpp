#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+7;
ll a[maxn];
int main(){
    string s;
    cin>>s;
    int l=s.size();
    if(s[0]==s[l-1]){
        if(l%2) cout<<"Second\n";
        else cout<<"First\n";
    }
    else{
        if(l%2) cout<<"First\n";
        else cout<<"Second\n";
    }
    return 0;
}
