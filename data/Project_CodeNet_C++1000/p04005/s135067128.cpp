#include <bits/stdc++.h>

using namespace std;

int main(){
long long a,b,c;
cin >> a >> b >> c;
vector<long long >p(3);
p[0] = a;
p[1] = b;
p[2] = c;
if(a%2 == 0 || b%2 == 0|| c%2 ==0){
	cout << 0 <<endl;
} 
else{
sort(p.begin(),p.end());
cout << p[0]*p[1] <<endl;
}

return 0;
}
