#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll GCD(ll a, ll b){ return a ? GCD(b % a, a) : b; }
int main(){
    string s;
    cin>>s;
    int n=s.size();
    map<char,int> m;
    for(int i=0; i<n; i++){
        m[s[i]]++;
    }
    int cnt=1e9;
    for(auto c:m){
        string s2=s;
        int cnt2=0;
        while(true){
            bool ok=true;
            for(int i=0; i<n-cnt2-1; i++){
                if(s2[i]!=s2[i+1]) ok=false;
            }
            if(ok){
                break;
            }

            string t=s2;
            for(int i=0; i<n-cnt2-1; i++){
                if(t[i+1]==c.first) s2[i]=t[i+1];
                else s2[i]=t[i];
            }
            cnt2++;
        }
        cnt=min(cnt,cnt2);
    }
    cout<<cnt<<endl;

}