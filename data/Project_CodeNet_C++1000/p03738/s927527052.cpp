#include <iostream>

using namespace std;

int main()
{
    int i;
    string a,b;
    cin>>a;
    cin>>b;
    if(a.length()>b.length()) {
            cout<<"GREATER\n";
            return 0;
    }
    if(a.length()<b.length()){
            cout<<"LESS\n";
            return 0;
    }

    long long int n=a.length(),x,y;
    if(n==b.length()){
    for(i=0;i<n;i++){
       x=a[i]-'0';
       y=b[i]-'0';
    if(x>y){
        cout<<"GREATER\n";
        return 0;
    }
    if(x<y){
        cout<<"LESS\n";
        return 0;
    }
    }}
    cout<<"EQUAL\n";
    return 0;
}
