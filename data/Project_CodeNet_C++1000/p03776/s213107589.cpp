#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

long long com[51][51];

void combination(int n){
  //combination
    com[0][0] = 1;
    for (int i = 1; i <=n; ++i) {
        for (int j = 0; j <= i; ++j) {
            com[i][j] += com[i-1][j];
            if (j > 0) com[i][j] += com[i-1][j-1];        
        }
    }
}

int main(void){
    int N, a, b; 
    cin >> N >> a >> b;
  
  combination(N);
  
    vector<long long> v(N);
  
    for (int i = 0; i < N; ++i) 
      cin >> v[i];
  
    sort(v.begin(), v.end(), greater<long long>());

    
    long long sum = 0;
  
    for (int i = 0; i < a; ++i){
      sum += v[i];
    }
  
    double ave = (double)(sum) / a;

    
    long long res = 0;
  
    int num = 0;
    for (int i = 0; i < N; ++i) if (v[i] == v[a-1]) ++num;
  
    if (v[0] == v[a-1]) {
        for (int j = a; j <= b; ++j) {
            res += com[num][j];
        }
    }
  
    else {
        int ans = 0;
        for (int i = 0; i < a; ++i) if (v[i] == v[a-1]) ans++;
        res = com[num][ans];
    }
  
    cout << fixed << setprecision(20) << ave << endl;
    cout << res << endl;
}
