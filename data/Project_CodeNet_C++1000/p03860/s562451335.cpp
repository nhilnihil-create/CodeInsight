#include <iostream>
using namespace std;
int main() {
    string a[3];
    for(int i = 0 ; i < 3; ++i)cin>>a[i];
    string s = "";
    for(int i = 0 ; i < 3; ++i){
        s += a[i][0];
    }
    cout<<s<<"\n";
}
