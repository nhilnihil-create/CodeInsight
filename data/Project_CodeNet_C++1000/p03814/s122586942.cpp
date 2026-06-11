#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;cin>>s;
    int n = s.size();
    int c1,c2;
    rep(i,n)if(s[i]=='A'){
        c1=i;
        break;
    }
    rep(i,n)if(s[n-1-i]=='Z'){
        c2=n-1-i;
        break;
    }
    cout<<c2-c1+1<<endl;
	return 0;
}

