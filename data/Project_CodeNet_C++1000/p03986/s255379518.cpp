#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	
	string str;
	char *c = new char[200005];
	scanf("%s",c);//scanf("%s",&c[0]);
	str = c;
	//cout<<str;
//	cin>>str;
	//scanf("%s",&str[0]);
	//int len=strlen(str);
	int flag=1;
	while(flag==1)
	{
		if(str.empty()) break;
		int i = 0;
	//int len=str.length();
		flag=0;
	    while (!str.empty()&&i < str.length()-1)
	    {   
	            if (str[i]=='S'&&str[i+1]=='T')
	            {
	                str.erase(i,2);
	                flag=1; 
	                i--;
	                i--;
	                //cout<<"delete."<<endl;
	                //break;
	            }
	        ++i; 
	    } 
	}
    //cout << str.length() << endl;
    printf("%d\n",str.length());
    return 0;

 } 