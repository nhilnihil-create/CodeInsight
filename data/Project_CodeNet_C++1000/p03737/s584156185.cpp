#include<iostream>
#include<string>

using namespace std;

int main(){
    int n = 'a' - 'A';
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    cout << (char)(s1[0] - n) << (char)(s2[0] - n) << (char)(s3[0] - n) << endl;
}