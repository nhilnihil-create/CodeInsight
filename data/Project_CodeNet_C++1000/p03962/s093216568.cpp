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
   set<int> s;
   int a, b, c;
   cin >> a;
   s.insert(a);
   cin >> b;
   s.insert(b);
   cin >> c;
   s.insert(c);

   cout << s.size();
   endl;

   bye;
    
}