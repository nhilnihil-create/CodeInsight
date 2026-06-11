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
  vec2(a,char,N,N,' ');
  vec2(b,char,M,M,' ');
  froop1(0,N){
    for(int j = 0;j < N;j++){
    cin >> a.at(i).at(j);  
    }
  }
  
  froop1(0,M){
    for(int j = 0;j < M;j++){
    cin >> b.at(i).at(j);  
    }
  }
  froop1(0,N - M + 1){
   for(int j = 0;j < N - M + 1;j++){
     int sw = 1;
    for(int k = 0;k < M;k++){
     for(int l = 0;l < M;l++){
       if(a.at(i + k).at(j + l) != b.at(k).at(l)) sw = 0;
    }
   }
     if(sw == 1){
      cout << "Yes" << endl;
       return 0;
     }
  }
  }
    cout << "No" << endl;
}