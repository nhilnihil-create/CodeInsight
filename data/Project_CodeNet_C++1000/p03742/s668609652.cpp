#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
    long long x,y;
    while(cin >> x >> y){
    if(fabs(x - y) <= 1) printf("Brown\n");
    else printf("Alice\n");
	}
}
