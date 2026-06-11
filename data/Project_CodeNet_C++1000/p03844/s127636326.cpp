#include <iostream>
#include <string.h>
using namespace std;

int main() {
    long a,b;
    char s;
    cin>>a>>s>>b;
    if(s=='+')cout<<a+b<<endl;
    else cout<<a-b<<endl;
	return 0;
}