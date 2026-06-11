#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define INF 1LL<<60
#define pi 3.14159265358979323846
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

int main(){
    int n;cin>>n;
    string s,t;cin>>s>>t;

    int ans=2*n;
    for(int i=0;i<n;i++){
        bool same=true;
        if(s[i]==t[0]){
            for(int k=0;k<n-i;k++){
                if(s[i+k]==t[k]){ans--;}
                else{same=false;}
            }
            if(!same){ans=2*n;}
            else{cout<<ans<<endl;return 0;}
        }
    }

    cout<<2*n<<endl;

    return 0;
}