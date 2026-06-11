#include<bits/stdc++.h>//万能头文件
using namespace std;
string s;
int judge=0;
int main()
{
    cin>>s;
    if(s[0]==s[s.size()-1])//满足条件1
        judge++;
    if(s.size()%2==1)//满足条件2
        judge++;
    if(judge==1)//满足一个是First
        cout<<"First"<<endl;
    else
        cout<<"Second"<<endl;
    return 0;
}