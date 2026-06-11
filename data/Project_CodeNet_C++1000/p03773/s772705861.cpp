#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int ans[100]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22};
int main(){
    int a,b;
    cin>>a>>b;
    int ab=a+b;
	cout<<ans[ab-1];
    return 0;
}
