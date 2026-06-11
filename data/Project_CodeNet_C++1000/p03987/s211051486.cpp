#include<bits/stdc++.h>
using namespace std;

int main() {

    //input from txt （提出時にこの箇所は削除すること）
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;
    cin >> N;
    int64_t MINF = -1e9;
    map<int64_t,int64_t> mp;
    vector<int64_t> vec(N+2,MINF);
    for(int i=1; i<N+1; i++){
        cin >> vec[i];
        mp[vec[i]] = i;
    }
    
    vector<int64_t> left(N+2);
    vector<int64_t> right(N+2);
    
    priority_queue<int64_t> PQ;
    PQ.push(MINF);
    
    for(int i=1; i<N+2; i++){
        if(vec[i] > PQ.top()){
            PQ.push(vec[i]);
        }
        else{
            while(vec[i] < PQ.top()){
                int64_t x = PQ.top();
                PQ.pop();
                int64_t y = mp[x];
                left[y] = i - y;
            }
            PQ.push(vec[i]);
        }
    }
    
    PQ.push(MINF);
    
    for(int i=N+1; i>=0; i--){
      if(vec[i] > PQ.top()){
          PQ.push(vec[i]);
      }
      else{
          while(vec[i] < PQ.top()){
              int64_t x = PQ.top();
              PQ.pop();
              int64_t y = mp[x];
              right[y] = y - i;
          }
          PQ.push(vec[i]);
      }
  }
    
    /*for(int i=0; i<N+2; i++){
        cout << left[i] << " " << right[i] << endl;
    }*/
    
    int64_t ans = 0;
    for(int i=1; i<N+1; i++){
        ans += left[i] * right[i] * vec[i];
    }
    
    cout << ans << endl;
    
}