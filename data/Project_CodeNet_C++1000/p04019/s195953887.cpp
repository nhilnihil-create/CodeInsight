#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;



int main() {
string S;
cin >> S;
int lo = S.size();
int n = 0;
int w= 0;
int s = 0;
int e = 0;
for(int i = 0; i < lo; i++){
if(S[i] == 'N') n++;
else if(S[i] =='W')w++;
else if(S[i] == 'S')s++;
else e++;
}
bool TZ, NB;
TZ = 0;
NB = 0;
if(n == 0 && s == 0)NB = 1;
if(w == 0 && e == 0)TZ = 1;
if(n > 0 && s > 0)NB = 1;
if(w > 0 && e > 0)TZ = 1;
if(TZ == 1 && NB == 1) cout << "Yes" << endl;
else cout << "No" << endl;





}

