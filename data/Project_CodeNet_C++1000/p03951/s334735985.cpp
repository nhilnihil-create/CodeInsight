#include<iostream>
#include<vector>
#include<string>
using namespace std;
 
int main(){
	long long n,m=0;
	string s,t;

    cin >> n;
    cin >> s >> t;

    for(long long i = n - 1; i >= 0; i--){
        if(s[n-1 - m] == t[i]){
            m++;
        }
    }

	cout << 2 * n - m << endl;
}