#include<iostream>
using namespace std;
int main(){
string a,b,c;
cin >> a>>b>>c;
int d=(int)a.at(0)-32;
int e=(int)b.at(0)-32;
int f=(int)c.at(0)-32;
cout << (char)d<<(char)e<<(char)f<<endl;
}