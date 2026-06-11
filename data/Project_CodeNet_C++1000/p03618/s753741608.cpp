#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;

int main(){
string A, chars="abcdefghijklmnopqrstuvwxyz"; cin >> A;
ULL l=A.size(), ans=l*(l-1)/2+1; map<char, ULL> freq;
for(ULL i=0; i<l; i++){ freq[A[i]]++; }
for(ULL i=0, q=0; i<26; i++){ q=freq[chars[i]]; ans-=q*(q-1)/2; }
cout << ans << "\n";
}