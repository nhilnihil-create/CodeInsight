#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n=s.size();
	int ok=0;
	for(int i=0;i<n;i++){
		int j=n-i-1;
		if(s[i]=='q'&&s[j]=='p'){}
		else {
		    if(s[i]=='b'&&s[j]=='d'){}
		    else {
			if(s[i]=='d'&&s[j]=='b'){}
		          else {if(s[i]=='p'&&s[j]=='q'){}
		          else ok=1;
	              }
            }
        }
    }
	if(ok==0){
		cout<<"Yes"<<endl;return 0;
	}
	ok=0;
	for(int i=0;i<n;i++){
		if(s[i]=='p')s[i]=='q';
		if(s[i]=='q')s[i]=='p';
		if(s[i]=='b')s[i]=='d';
		if(s[i]=='d')s[i]=='b';
	}
	for(int i=0;i<n;i++){
		int j=n-i-1;
		if(s[i]=='q'&&s[j]=='p'){}
		else {
		    if(s[i]=='b'&&s[j]=='d'){}
		    else {
			if(s[i]=='d'&&s[j]=='b'){}
		          else {if(s[i]=='p'&&s[j]=='q'){}
		          else ok=1;
	              }
            }
        }
    }
    if(ok==0)cout<<"Yes"<<endl;
    else cout<<"No";
	return 0;
} 