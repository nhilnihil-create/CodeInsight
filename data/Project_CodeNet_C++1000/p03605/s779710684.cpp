#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
    if(n%10==9||n/10==9) {
        cout<<"Yes"<<'\n';
        return 0;
    } else {
        cout<<"No"<<'\n';
	    return 0;
    }
}