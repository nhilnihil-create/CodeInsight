#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    int r=0,p=0;
    long ans=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='p'){
            if(p==r){
                ans--;
                r++;
            }else {
                p++;
            }
        }else if(s[i]=='g'){
            if(p==r){
                r++;
            }else{
                ans++;
                p++;
            }
        }
    }
    cout<<ans<<endl;
	return 0;
}