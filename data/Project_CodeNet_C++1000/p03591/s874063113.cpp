#include <bits/stdc++.h>
using namespace std;

int main() {


//long long a,b;
//int *num=new int[4];
//char *s=new char[3];
string s;
cin >> s;

//if (s.find("AC") != std::string::npos) {

int n=(int)(s.length());
int res=0;

if(n<=3){
cout << "No";
}else if(s[0]=='Y' && s[1]=='A' && s[2]=='K' && s[3]=='I'){

cout << "Yes";
}else{
cout << "No";

}


}
