#include<iostream>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
    
    char a[100010]={0};
    char b[100010]={0};
    gets(a);
    int l=0;
    int i=0,j=strlen(a)-1;
    if(strlen(a)%2!=0){
    	cout<<"No";
    	return 0;
	}
    while(i<j){
		if(a[i]=='b' && a[j]=='d' || a[i]=='d' && a[j]=='b' || a[i]=='p' && a[j]=='q' || a[i]=='q' && a[j]=='p') {
			i++;j--;
		}
        else
        {
            printf("No");
            return 0;
        }
	}
	cout<<"Yes";
    return 0;
    
}