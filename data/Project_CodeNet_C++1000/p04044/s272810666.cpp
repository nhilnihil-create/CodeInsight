#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    string x[a+5];
    for(int i=1;i<=a;i++){
        cin>>x[i];
    }
    sort(x+1,x+1+a);
    for(int i=1;i<=a;i++){
        cout<<x[i];
    }
    cout<<endl;
}