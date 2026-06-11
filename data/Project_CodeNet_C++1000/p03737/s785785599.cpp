#include <bits/stdc++.h>

using namespace std;

int main(){
    string a,b,c;
    cin>>a>>b>>c;

    char diff = 'A'-'a';

    char s1=a[0]+diff;
    char s2=b[0]+diff;
    char s3=c[0]+diff;

    cout<<s1<<s2<<s3<<endl;

}