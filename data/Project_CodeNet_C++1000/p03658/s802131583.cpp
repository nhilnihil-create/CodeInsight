 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
 //int nax = max_element(p.begin(),p.end())-p.begin();
 //int nin = max_element(p.begin(),p.end())-p.begin();

 int main(){
     int n,k;
     cin >> n >> k;
     vector<int> l(n);
     rep(i,n){
         cin >> l[i];
     }
     sort(l.begin(),l.end(),greater<int>());
     int sum = 0;
     rep(i,k){
         sum+=l[i];
     }
     cout << sum << endl;
     return 0;
 }