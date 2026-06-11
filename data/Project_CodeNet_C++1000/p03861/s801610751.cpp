#include<iostream>
using namespace std;

int main(){
long long a,b,x;
cin >> a >> b >> x;
long long left = a/x;
if(left*x < a){
if((left+1)*x > b){
cout << 0 << '\n';
}else{
if( b % x == 0 ){
cout << (1 + (b-a)/x) << '\n';
}else{
long long temp = (left+1)*x;
cout << (1 + (b-temp)/x) << '\n';
}
}
}else{
cout << (1 + (b-a)/x) << '\n';
}
}