#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    bool a=1;
    for(int i=97;i<=122;i++)
    {
        a=1;
        for(int j=0;s[j]!='\0';j++)
        {
            if(char(i)==s[j])
            {
                a=0;
                continue;
            }

    }
 if(a==1){
            cout<<char(i);
            break;
}
    }
 if(a==0)
        cout<<"None";
	return 0;
	}



