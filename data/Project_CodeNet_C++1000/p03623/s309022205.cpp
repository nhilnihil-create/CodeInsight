#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  int x,a,b;
  cin >> x >> a >> b;
  if(abs(x-a) <= abs(x-b)){
    cout << "A" << endl;
  } else { 
    cout << "B" << endl;
  }
}

