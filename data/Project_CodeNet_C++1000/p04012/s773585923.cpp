
//usr_name : paras.gautam243
//dated :

#include<iostream>
using namespace std;

int main(){
//#ifndef ONLINE_JUDGE
   //freopen("in.txt", "r", stdin);
   //freopen("out.txt", "w", stdout);
//#endif

ios::sync_with_stdio(0);
cin.tie(0);


//...
string s;
cin>>s;
int a[26]={0};
for(char c:s){
    ++a[c-'a'];
}

for(int i=0; i<26; i++){
	if (a[i]%2!=0){
		cout<<"No";
		return 0;
     } 
     	
}
cout<<"Yes";

return 0;
}

