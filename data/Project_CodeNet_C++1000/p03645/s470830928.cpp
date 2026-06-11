#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)

#define ll long long

#define pq(name,type) priority_queue<type> name
#define vec(name,type,length,value) vector<type> name(length,value)
#define vec2(name,type,length,width,value) vector<vector<type>> name(length,vector<type>(width,value));

int main(){
	int N,M;
  cin >> N >> M;
  vector<vector<int>> a(N + 1);
  froop1(0,M){
    int b,c;
    cin >> b >> c;
    a.at(b).push_back(c);
  }
  
  int sw = 0,s1 = a.at(1).size();
  froop1(0,s1){
    int current = a.at(1).at(i),s = a.at(current).size();
    for(int j = 0;j < s;j++){
      if(a.at(current).at(j) == N){
        sw = 1;
      }
    }
  }
  if(sw == 1){
	cout << "POSSIBLE" << endl;
  }else{
    cout << "IMPOSSIBLE" << endl;
  }

return 0;
}