#include <bits/stdc++.h> 

using namespace std;

pair<int,int> slove(string& str){
	int len=str.length();
	for(int i=0;i<len-2;i++){
		if(str[i+1]==str[i]){
			return make_pair(i+1,i+2);
		}else if(str[i+2]==str[i]){
			return make_pair(i+1,i+3);
		}
	}
	if(str[len-2]==str[len-1])
		return make_pair(len-1,len);
	return make_pair(-1,-1);
}

int main(){
	string str;
	cin>>str;
	auto ans=slove(str);
	cout<<ans.first<<' '<<ans.second<<endl;
	return 0; 
}