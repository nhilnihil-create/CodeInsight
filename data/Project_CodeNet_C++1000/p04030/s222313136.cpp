 #include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    string ans = "";
    for(int i=0;i<str.length();i++){
    	if(str[i]=='0'){
    		ans+='0';
    	}
    	else if(str[i]=='1'){
    		ans+='1';
    	}
    	else if(str[i]=='B'){
    		if(!ans.empty()){
    			ans = ans.substr(0,ans.length()-1);
    		}
    	}
    }
    cout << ans << endl;
	return 0;
}