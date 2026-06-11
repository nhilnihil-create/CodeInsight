#include<bits/stdc++.h>//万能头文件
using namespace std;//名字空间
int main(){//主函数
    string AC;
    cin>>AC;
    string b=AC;
    reverse(AC.begin(),AC.end());
    for(int i=0;i<AC.size();i++)
    {
        if(AC[i]=='b') AC[i]='d';
        else if(AC[i]=='d') AC[i]='b';
        else if(AC[i]=='p') AC[i]='q';
        else if(AC[i]=='q') AC[i]='p';
    }
    if(AC==b) cout<<"Yes";//符合就输出"Yes"
    else cout<<"No";//否则就输出"No"
    return 0;
}