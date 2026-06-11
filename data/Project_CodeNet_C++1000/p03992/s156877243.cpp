#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    string s;
    cin>>s;
    for(int i=0;i<4;i++){
        cout<<s[i];
    }
    cout<<" ";
    for(int i=4;i<s.size();i++){
        cout<<s[i];
    }
    cout<<endl;
    
}