#include<bits/stdc++.h>
using namespace std;
int main()
{
        string s;
        cin>>s;
        int flag = 1;
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]==s[i+1])
            {
                cout<<i+1<<" "<<i+2<<endl;
                flag = 0;
                break;
            }
            else if((i<s.length()-2)&&(s[i]==s[i+2]))
            {
                cout<<i+1<<" "<<i+3<<endl;
                flag = 0;
                break;
            }
        }
        if(flag==1)
        {
            cout<<-1<<" "<<-1<<endl;
        }

}
