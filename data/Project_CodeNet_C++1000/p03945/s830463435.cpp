#include <iostream>
using namespace std;

int main() {
string color="";
cin>>color;
int x=0;
for(int i=1; i<color.length(); i++){
if(color[i]!=color[i-1]){
x=x+1;
}
}
cout<<x<<'\n';
}