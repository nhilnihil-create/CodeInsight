#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin>>s;
    int size = s.size();
    string syouryaku = s[0] + to_string(size-2) + s[size-1];
    cout<<syouryaku<<endl;
}