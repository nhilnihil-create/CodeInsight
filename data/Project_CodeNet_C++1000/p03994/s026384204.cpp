#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    string s;
    cin>>s;
    ll k;
    cin>>k;
    rep(i, s.size()){
        int c = s[i]-'a';
        if(c>0){
            if(k>=26-c){
                k -= 26-c;
                s[i] = 'a';
            }
        }
    }
  
    if(k>0){
        k = k%26;
        s[s.size()-1] += k;
    }
    cout<<s<<endl;
    return 0;
}