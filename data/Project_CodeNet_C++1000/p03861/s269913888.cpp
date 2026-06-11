#include <bits/stdc++.h>
using namespace std;

long long f(long long s,long long t){
if(s==-1)return 0;
else    return s/t+1;
}
int main(){
long long a,b,x;
cin >> a >> b >> x; 
cout << f(b,x)-f(a-1,x) << endl;
}