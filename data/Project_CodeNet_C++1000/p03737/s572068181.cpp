#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(void){
    string s1,s2,s3;
    char c1,c2,c3;
    cin >> s1 >> s2 >> s3;
    c1=s1.front();
    c2=s2.front();
    c3=s3.front();
    c1 -= 0x20;
    c2 -= 0x20;
    c3 -= 0x20;
    cout << c1 << c2 << c3 << "\n";
    return 0;
}