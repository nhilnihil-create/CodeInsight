#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int main() {
    int A,B,a,b;
    cin>>A>>B>>a>>b;
    if(A%a==0&&B%b==0) return puts("No"),0;
    int k=999999999/(a*b-1);
    puts("Yes");
    for(int i=1;i<=A;i++) {
	for(int j=1;j<=B;j++) {
	    if(i%a==0&&j%b==0) printf("%d ",-(a*b-1)*k-1);
	    else printf("%d ",k);
	}
	puts("");
    }
    return 0;
}