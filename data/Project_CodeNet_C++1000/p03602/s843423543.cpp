#include <bits/stdc++.h>
#include <cctype>
#include <cmath>
#include <string>
using namespace std;
int main(){
    int N;
    unsigned long long sum = 0;
    bool judge = true;
    cin >> N;
    vector<int> A(N*N);
    for(int i = 0;i < N;i ++){
        for(int j = 0;j < N;j ++){
            cin >> A.at(N*i+j);
        }
    }
    for(int u = 0;u < N;u ++){
        for(int v = 0;v < N;v ++){
          	if(u >= v) continue;
          	int countx = 0;
            for(int x = 0;x < N;x ++){
              	if(x == u || x == v) continue;
                if(A.at(u*N+v)<A.at(u*N+x)+A.at(x*N+v)){
                  	countx ++;
                }
                if(A.at(u*N+v)>A.at(u*N+x)+A.at(x*N+v)){
                    judge = false;
                }
            }
          	if(countx == N-2) sum += A.at(u*N+v);
        }
    }
  	int ans = -1;
    if(judge){
 		cout << sum << endl;
    }else{
      	cout << ans << endl;
    }
}