#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n,a,b;cin>>n>>a>>b;
    int ca = 0;
    int cb = 0;
    string s;cin>>s;
    rep(i,n){


        if(s[i]=='a' && (ca + cb < a + b)){
          ++ca;
          cout<<"Yes"<<endl;

        }
        else if(s[i]=='b' && (ca + cb < a + b) && (cb < b)){
          ++cb;
          cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;        
    }
	return 0;
}