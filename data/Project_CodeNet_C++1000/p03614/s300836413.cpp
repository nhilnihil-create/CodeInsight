#include <iostream>
using namespace std;

int main() {
    int n, p, b, c = 0;
    cin >> n >> b;
    for(int i=2;i<=n;i++){
        cin >> p;
        if(b == i-1 || (i == n && p == i)){
            c++;
        }else{
            b = p;
        }
    } cout << c << endl;
	return 0;
}