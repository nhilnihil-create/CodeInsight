#include <iostream>
#include <string>
using namespace std;
int main(){
    string a,b;
    cin >> a >> b;
    if(a.size() < b.size()) puts("LESS");
    else if(b.size() < a.size()) puts("GREATER");
    else {
        for(int i = 0; i < a.size(); i++) {
            if(a[i] - '0' < b[i] - '0') {
                puts("LESS");
                return 0;
            }
            else if (b[i] - '0' < a[i] - '0') {
                puts("GREATER");
                return 0;
            }
        }
        puts("EQUAL");
    }
    return 0;
}