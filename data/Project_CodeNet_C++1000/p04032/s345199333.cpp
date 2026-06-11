#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string x;
    cin>>x;
    int len=x.length();
    for(int i=0;i<len-1;i++){
        if (x[i]==x[i+1]){
            printf("%d %d\n",i+1,i+2);
            return 0;
        }
    }
    for(int i=0;i<len-2;i++){
        if (x[i]==x[i+2]){
            printf("%d %d\n",i+1,i+3);
            return 0;
        }
    }
    printf("-1 -1\n");
    
}