#include <bits/stdc++.h>
using namespace std;
 
int main() {
long long A, B, C;
cin >> A >> B >> C;
bool check = 0;
bool mugen = 0;
if(A % 2 == 1 || B%2 == 1 || C%2 == 1){
    check = 1;
}
long long afa, afb, afc;
int count = 0;
while(check == 0){

afa = A / 2;
afb = B / 2;
afc = C / 2; 
A = afb + afc;
B = afa + afc;
C = afa + afb;
count++;


if(A % 2 == 1 || B%2 == 1 || C%2 == 1) check = 1;
if(count > 1000){
check = 1;
mugen = 1;
break;
}

}
if(mugen == 1)cout << -1 << endl;
else cout << count << endl;



}