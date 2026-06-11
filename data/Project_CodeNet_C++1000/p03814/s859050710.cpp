#include <bits/stdc++.h>
using namespace std;
string s;
int tot;
int main() {
cin>>s;
tot=s.rfind("Z")-s.find("A")+1;
cout<<tot<<endl;
}
