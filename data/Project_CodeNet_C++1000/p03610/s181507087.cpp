#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(i%2==0){
            cout<<s[i];
        }
    }
    cout<<endl;
    return(0);
}