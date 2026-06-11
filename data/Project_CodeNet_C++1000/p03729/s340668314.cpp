#include <iostream>
#include <string.h>
using namespace std;

int main() {
    string a,b,c;cin>>a>>b>>c;
    int a1,b1;
    a1 = a.size();
    b1 = b.size();
    if(a[a1-1]==b[0] && b[b1-1]==c[0])cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
	return 0;
}