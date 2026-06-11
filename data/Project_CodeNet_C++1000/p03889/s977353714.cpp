#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
string s;
int main(){
    cin>>s;
	int k=s.size();
    if(k%2!=0){
        printf("No");
        return 0;
	}
    for(int i=0;i<k/2;i++){
        if(s[i]=='b'&&s[k-i-1]!='d'){
            printf("No");
            return 0;
        }
        if(s[i]=='d'&&s[k-i-1]!='b'){
            printf("No");
            return 0;
        }
        if(s[i]=='q'&&s[k-i-1]!='p'){
            printf("No");
            return 0;
        }
        if(s[i]=='p'&&s[k-i-1]!='q'){
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}