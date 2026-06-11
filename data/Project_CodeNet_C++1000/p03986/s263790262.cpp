#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string str;
int n;
bool pre;
int main()
{
    cin >> str; 
    if(str[0]=='S')
        pre = 1;
    else
    {
        pre = 0;
    }
    int i = 1;
        while (str.size())
        {     

            while (pre)
            {
                    if (str[i] == 'T')
                    {
                        str.erase(i - 1, 2);
                        i -=1;
                        
                        if (i >= str.size())
                            break;
                        if(i-1>=0&&str[i-1]=='S')
                            pre = 1;
                            else
                                pre = 0;                            
                    }
                    else
                        break;
            }

            if (i >= str.size())
                break;
            if(str[i]=='S')
            { 
                pre = 1;
            }

            i++;
            if(i>=str.size())
                break;
    }
    cout << str.size() << endl;
   // system("pause");
}