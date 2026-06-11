    #include <bits/stdc++.h>
    using namespace std;
    int main(){
    char a[20]="CODEFESTIVAL2016";
    char s[20];
    int b=0;
    cin>>s;
    for(int i=0;i<16;i++)
    if(a[i]!=s[i])
    b++;
    cout<<b<<endl;
    return(0);
    }