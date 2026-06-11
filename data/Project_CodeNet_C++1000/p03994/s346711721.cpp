#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    string s;
    int k;
    cin>>s>>k;
    int n=s.size();
    rep(i,n){
        if(s[i]!='a'){
            int x=26-(s[i]-'a');
            if(k>=x){
                s[i]='a';
                k-=x;
            }
        }
        
    }
    

    k%=26;
    
    while(k>0){
        if(s[n-1]=='z') s[n-1]='a';
        else s[n-1]++;
        k--;
    }


    cout<<s<<endl;
} 
