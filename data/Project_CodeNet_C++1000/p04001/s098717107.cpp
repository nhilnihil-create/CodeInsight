#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000
typedef long long ll;
int main(){
    ll sum=0;
    string s;cin>>s;
    bool b[s.size()];
    memset(b,0,s.size()*sizeof(bool));
    while(!b[0]){
        int j=s.size()-1;
        while(b[j])b[j--]=0;
        b[j]=1;
        ll tmp=0;
        for(int i=0;i<s.size();++i){
            tmp=tmp*10+s[i]-'0';
            if(b[i+1]){/*cout<<tmp<<endl;*/sum+=tmp;tmp=0;}
        }
        sum+=tmp;
    }
    cout<<sum<<endl;
    return 0;
}
