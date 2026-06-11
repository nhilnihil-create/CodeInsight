#include<bits/stdc++.h>
#define INFTY 10000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const int MOD=1000000007;
const int di[4] = {-1,0,1,0};
const int dj[4] = {0,-1,0,1};
const int INF = 1e9;
const int A = 1000005;
int main(){
    string s,t={};cin>>s;
    int sz = s.size();
    int i = sz-1;
    while(i>=4)
    {
        //cout<<i<<t<<endl;
        if(i>5&&s.substr(i-6,7)=="dreamer"){t = "dreamer"+t;i-=7;}
        else if(i>4&&s.substr(i-5,6)=="eraser"){t = "eraser"+t;i-=6;}
        else if(s.substr(i-4,5)=="erase"){t = "erase"+t;i-=5;}
        else if(s.substr(i-4,5)=="dream"){t = "dream"+t;i-=5;}
        else{
            cout<<"NO"<<endl;
            return 0;
        }
            
    }
    
    if(s==t)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}