#include "cstdio"
#include "string"
#include "iostream"
using namespace std;
int main(){
	string s;
	cin>>s;
	int x=s.size();
	if(s[0]==s[x-1]){
	if(x%2==0){
		printf("First\n");return 0;
	}
	else{
		printf("Second\n");return 0;
	}
	}
	else{
		if(x%2==0){
		    printf("Second\n");return 0;
	    }
	    else {
		    printf("First\n");return 0;
	    }
	}
}