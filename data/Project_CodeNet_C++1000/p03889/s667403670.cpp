#include<bits/stdc++.h>
using namespace std;
   char s[100860];
int main(){
 
    scanf("%s",&s);
    int n=strlen(s);
    if(n%2!=0){
        cout<<"No"<<endl;
        return 0;
    }
    else {
        for(int i=0;i<=n/2;i++) {
		int num=abs(s[i]-s[n-1-i]);
		if(num!=1&&num!=2)
		{
			cout<<"No"<<endl;
			return 0;
		}
    }}
    cout<<"Yes"<<endl;
    return 0;
}