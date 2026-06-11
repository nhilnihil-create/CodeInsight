#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define bye return 0
#define Yes cout << "Yes" << "\n"
#define No  cout << "No" << "\n"
#define YES cout << "YES" << "\n"
#define NO cout << "NO" << "\n"
#define endl cout << "\n"

void func(vector<int> &v){
	reverse(v.begin(), v.end());
}

int main(){
	/*ios::sync_with_stdio(false);
    cin.tie(NULL);*/
   vector<int> v;
   int a, b, c;
   cin >> a;
   v.push_back(a);
   cin >> b;
   v.push_back(b);
   cin >> c;
   v.push_back(c);

   sort(v.begin(), v.end());

   int d = v[0]+v[1];
   int e = v[2];
   if(d==e){
   	Yes;
   }else{
   	No;
   }
   bye;
    
}