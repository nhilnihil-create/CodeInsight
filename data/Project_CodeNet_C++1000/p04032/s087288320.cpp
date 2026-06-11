#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    // We are Looking for a Contiguos String ( or SubString) where more than Half the Characters are Same
	// If no such thing exists print -1 -1 
	// If such Sub String do exists then print its starting and end positions {If more than one Solution exists then print any one of them}
    string s;
	ll b=-1,e=-1;
	cin>>s;
	for(size_t i=0;i<s.size()-1;i++){
          if(s[i]==s[i+1]){
              b=i+1;       // I is Index, I+1 is Pos
			  e=i+1+1;
			  break;
		  }else if(i <s.size()-2 && s[i]==s[i+2]){
              b=i+1;
			  e=i+2+1;
			  break;
		  }
	}
	cout<<b<<" "<<e;
    return 0;
}