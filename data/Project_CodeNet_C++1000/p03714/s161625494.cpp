#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)


int main() {
  int N;cin >> N;
  vector<int> A(3*N);
  vector<int> B(3*N);
  for (int i = 0;i < 3*N;i++){
    int c;cin >> c;
    A.at(i) = c;
    B.at(3*N-1-i) = c;
  }


  priority_queue<int> pq;
  priority_queue<int> qp;
  long long int red,blue;
  for (int i = 0;i < N;i++){
    red+=-A.at(i);
    pq.push(-A.at(i));
    blue+=B.at(i);
    qp.push(B.at(i));
  }
  vector<long long int> R(N+1);
  vector<long long int> L(N+1);
  R.at(0) = -red;
  L.at(0) = blue;
  for (int i = N;i < 2*N;i++){
    red+=-A.at(i);
    pq.push(-A.at(i));
    red-=pq.top();
    pq.pop();

    blue+=B.at(i);
    qp.push(B.at(i));
    blue-=qp.top();
    qp.pop();

    R.at(i+1-N) = -red;
    L.at(i+1-N) = blue;
    
    //cout << -red << " " << blue << endl;
  }
  long long int MAX = -pow(10,14);
  for (int i = 0;i <= N;i++){
    MAX = max(MAX,R.at(i)-L.at(N-i));
    //cout << R.at(i) << " " << L.at(N-i) << endl;
  }
  cout << MAX << endl;






}       