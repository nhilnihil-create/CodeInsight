#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> v = {"ABC"};
    string str;
    cin >> str;
    v.push_back(str);
    for(auto i:v)
    cout<<i;
    cout<<"\n";
    return 0;
}
