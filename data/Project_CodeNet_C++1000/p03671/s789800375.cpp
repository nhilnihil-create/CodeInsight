#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int a,b,c;
    cin>>a>>b>>c;
    cout<<a+b+c-max(max(a,b),c);
	return 0;
}
