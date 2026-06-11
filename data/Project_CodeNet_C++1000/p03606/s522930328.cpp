#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
int N,p,q,people;
people=0;
cin>>N;
for(int i = 0;i<N;i++){
cin>>p>>q;
people +=q-p+1;
}
cout<<people;}
