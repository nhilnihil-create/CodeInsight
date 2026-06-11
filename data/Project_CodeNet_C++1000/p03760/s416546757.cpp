#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;



int main() {
string S, T;
cin >> S >> T;
int lo = S.size();
int la = T.size();
for(int i = 0; i < lo; i++){
if(i == lo-1 && lo != la) cout << S[i];
else cout << S[i] << T[i];
}

}

