#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string s;
    cin>>s;
    string a=s.substr(0,4);
    string b=s.substr(4,8);
    cout<<a<<" "<<b<<endl;
    return 0;
}