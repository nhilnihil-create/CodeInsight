#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    char ch[19];
    cin>>ch;
    if(ch[5]==',')
        ch[5]=' ';
    if (ch[13]==',')
        ch[13]=' ';
    cout<<ch<<endl;

    return 0;
}
