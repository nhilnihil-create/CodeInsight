#include<iostream>
using namespace std;
int main()
{ 
  char a[16]={'C','O','D','E','F','E','S','T','I','V','A','L','2','0','1','6'};
    char b[16];
    int c=0;
	
	 for(int i=0;i<16;i++)
	 {   cin>>b[i];
	     if(b[i]!=a[i]) c++;  
	 }
    cout<<c<<endl;
    return 0;
}