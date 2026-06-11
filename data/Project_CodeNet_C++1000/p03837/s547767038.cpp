# include <iostream>

using namespace std;



int main(){
  int N, M;
  int a, b, c, count;
  int d[100][100], dc[100][100];

  cin >> N >> M;
  
  // initialize graph
  for(int n1 = 0; n1 < N; n1++) {
    for(int n2 = 0; n2 < N; n2++) {
      d[n1][n2] = 1001;
      dc[n1][n2] = 0;
    }
  }

  // load the graph
  for(int m = 0; m < M; m++) {
    cin >> a >> b >> c;
    d[a-1][b-1] = c;
    d[b-1][a-1] = c;
    dc[a-1][b-1] = c;
    dc[b-1][a-1] = c;
  }
  
  for(int k = 0; k < N; k++) {
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
	d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  count = 0;
  for (int n1 = 0; n1 < N; n1++) {
    for (int n2 = n1+1; n2 < N; n2++) {
      if (d[n1][n2] - dc[n1][n2] < 0) {
	count ++;
      }
    }
  }

  cout << count << endl;

  return 0;
}
