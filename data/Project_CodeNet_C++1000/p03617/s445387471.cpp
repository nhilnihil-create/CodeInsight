#include <bits/stdc++.h>
using namespace std;
const int INF=999999999;
int main() {
 int64_t Q,H,S,D,N;
 cin>>Q>>H>>S>>D>>N;
 cout<<min(min({4*Q,2*H,S})*N , D*(N/2)+min({4*Q,2*H,S})*(N%2))<<endl;
 return 0;}