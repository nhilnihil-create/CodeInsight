#include <bits/stdc++.h>
using namespace std;
int main()
{   int n,x=0,m=0;cin>>n;
    char a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]=='I'){
            x+=1;
            if(x>m)
                m=x;
        }
        else {
             x-=1;
            if(x>m)
                m=x;
        }
    }
    
    cout<<m<<endl;
return 0;
}




