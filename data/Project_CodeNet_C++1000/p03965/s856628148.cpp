#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string x;
    cin>>x;
    int rock=0,paper=0;

    int ans=0;
    for(int i=0;i<x.length();i++){
        if (x[i]=='g'&& rock>paper){
            ans++;
            paper++;
        }else if (x[i]=='g'&&rock<=paper){
            rock++;
        }else if (x[i]=='p'&&rock<=paper){
            ans--;
            rock++;
        }
        else if(x[i]=='p'&&rock>paper){
            paper++;
        }
    }
    printf("%d\n",ans);
}