#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    cin>>s;
    if((s[0]==s[s.size()-1] && s.size()%2==0) || (s[0]!=s[s.size()-1] && s.size()%2)){
		cout<<"First"<<endl;
	}
    else{
		cout<<"Second"<<endl;
	}
    return 0;
}