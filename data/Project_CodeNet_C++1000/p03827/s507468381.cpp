#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int n, x = 0;
	cin >> n;
	string s;
    cin >> s;
    int max = 0;
    for (int i = 0; i<n; i++){
        if(s[i]=='I'){
            x++;
        } else if (s[i]=='D'){
            x--;
        }
        if (x > max){
            max = x;
        }
    }
    printf("%d\n", max);
}
