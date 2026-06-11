#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;cin>>s;
    int n = s.size();
    sort(s.begin(),s.end());
    rep(i,n-1)if(s[i+1]==s[i]){
        cout<<"no"<<endl;
        return 0;
    }
    cout<<"yes"<<endl;
	return 0;
}