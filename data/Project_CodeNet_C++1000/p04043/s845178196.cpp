#include<iostream>
#include<map>
using namespace std;
int main()
{
    int a,i;
    map<int,int>b;
    for(i=0;i<3;i++){
        cin>>a;
        b[a]++;
    }
    if(b[5]==2&&b[7]==1)
        puts("YES");
    else
        puts("NO");
}
