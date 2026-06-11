#include<iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    for(int i = 1; i < s.length(); ++i) {
        if(s[i] == s[i-1]) {
            printf("%d %d\n",i,i+1);
            return 0;
        }
        if(i >= 2) {
            if(s[i] == s[i-2]) {
                printf("%d %d\n",i-1,i+1);
                return 0;
            }
        }
    }
    printf("-1 -1\n");
return 0;
}