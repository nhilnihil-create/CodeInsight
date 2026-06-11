#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    int n;
    cin>>n;
    if(n/100==n%10)cout<<"Yes";
    else cout<<"No";
	return 0;
}
