#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
string ch;
int main()
{

    cin>>ch;
    int mls=ch.length();
        if((mls%2==0)&&(ch[0]==ch[mls-1])){
            cout<<"First"<<endl;return 0;
        }
        if((mls%2!=0)&&(ch[0]==ch[mls-1])){
            cout<<"Second"<<endl;return 0;
        }
        if((mls%2==0)&&(ch[0]!=ch[mls-1])){
            cout<<"Second"<<endl;return 0;
        }
        if((mls%2!=0)&&(ch[0]!=ch[mls-1])){
            cout<<"First"<<endl;return 0;
        }
    }
