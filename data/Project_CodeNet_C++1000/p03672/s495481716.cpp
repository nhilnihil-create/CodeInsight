#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    for(int i=s.size()-2;i>=0;i--){
        int c=0;
        for(int j=0;j<i/2;j++){
            if(i%2==1){
                break;
            }
            if(s[j]==s[j+i/2])
                c++;
        }
        if(i/2==c){
            cout<<i<<endl;
            return(0);
        }
    }
    return(0);
}