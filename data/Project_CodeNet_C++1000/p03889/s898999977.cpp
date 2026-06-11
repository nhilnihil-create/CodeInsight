#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
string a,b;
int main()
{
    cin>>a;
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]=='p') b+='q';
        else if(a[i]=='q') b+='p';
        else if(a[i]=='b') b+='d';
        else b+='b';
    }
    if(a==b) printf("Yes");
    else printf("No");
    return 0;
}
