#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int h,w,x,y;
    string str;
    cin>>h>>w;
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            cin>>str;
            if(str=="snuke"){
                x=i;
                y=j;
            }
        }
    }
    printf("%c%d\n",y+'A',x+1);
    return 0;
}
