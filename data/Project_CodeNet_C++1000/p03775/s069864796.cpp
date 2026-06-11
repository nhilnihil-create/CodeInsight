#include <bits/stdc++.h>
using namespace std;


int main(){
    long long n;
    cin >> n;
    int note = 100;
    for (int i=1; i <= sqrt(n)+1;i++){
        if (n%i == 0){
			long long a = n/i;
			int b = to_string( max((long long)i,a) ).length();
			note = min(note,b);
        }
    }
    cout << note << endl;
}