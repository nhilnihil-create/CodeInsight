#include <bits/stdc++.h>
using namespace std;
  
int main() {
    int N,M;
    cin >> N >> M;
    vector <int> data(M*2);
    
    
    for (int i=0;i<M*2;i++) {
        cin >> data.at(i);
    }
    
    
    for (int n=1;n<N+1;n++) {
    int count=0;    
    for (int i=0;i<data.size();i++) {
        if(data.at(i) == n){
            count++;
        }
    }
    cout << count << endl;
    
    }
    
    
    
   }

 