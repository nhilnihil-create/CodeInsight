#include <iostream>
#include <string>
using namespace std;
int main(){
    string a,b,c; cin >> a >> b >> c;
    int alen = a.size();
    int blen = b.size();
    if(a[alen-1] == b[0] && b[blen-1] == c[0]) puts("YES");
    else puts("NO");
    return 0;
}