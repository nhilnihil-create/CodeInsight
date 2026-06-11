#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
    cin >> N;
    int n = N/100;
    int m = N%10;
    if(n==m){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
    }
}
