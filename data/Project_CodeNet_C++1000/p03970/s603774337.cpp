#include<iostream>
using namespace std;
int main(){
    char a[16];
    cin>>a;
    int cnt=0;
    if(a[0]!='C')
    	cnt++;
    if(a[1]!='O')
    	cnt++;
    if(a[2]!='D')
    	cnt++;
    if(a[3]!='E')
    	cnt++;
    if(a[4]!='F')
    	cnt++;
    if(a[5]!='E')
    	cnt++;
    if(a[6]!='S')
    	cnt++;
    if(a[7]!='T')
    	cnt++;
    if(a[8]!='I')
    	cnt++;
    if(a[9]!='V')
    	cnt++;
    if(a[10]!='A')
    	cnt++;
    if(a[11]!='L')
    	cnt++;
    if(a[12]!='2')
    	cnt++;
    if(a[13]!='0')
    	cnt++;
    if(a[14]!='1')
    	cnt++;
    if(a[15]!='6')
    	cnt++;
    cout<<cnt;
}