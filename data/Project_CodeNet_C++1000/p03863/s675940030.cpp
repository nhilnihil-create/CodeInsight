#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin>>s;
	if(s[0]==s[s.size()-1])
    	if(s.size()&1)
   	        printf("Second");
  	    else
            printf("First");
    else
        if(s.size()&1)
            printf("First");
        else
            printf("Second");
	return 0;
}