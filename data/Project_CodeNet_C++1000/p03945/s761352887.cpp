#include <bits/stdc++.h>
using namespace std;
char a[100005];
int main() {
    cin>>a;
    int len=strlen(a),cnt=0;
    for(int i=1;i<len;i++){
        if(a[i]!=a[i-1])cnt++;
    }
    std::cout <<cnt << std::endl;
    return 0;
}
