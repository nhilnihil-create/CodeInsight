#include <bits/stdc++.h>
using namespace std;
#include <math.h>
int main() {
 int64_t Q,H,S,D,N;
 cin>>Q>>H>>S>>D>>N;
 cout<<min({4*Q,2*H,S})*(N%2)+N/2*min(2*min({4*Q,2*H,S}),D)<<endl;
 return 0;}