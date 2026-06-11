#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

//read_kaisetsu
int main() {
    string s;cin>>s;
    int n=s.size();
    int c_g=0;
    int c_p=0;
    int ans=0;
    rep(i,n){
        if(s[i]=='g')++c_g;
        else ++c_p;
    }
//    int ma = c_g - c_p;
//    reverse(s.begin(), s.end());
//    rep(i,ma)if(s[i]=='g')++ans;
    cout<<n/2 - c_p<<endl;
	return 0;
}