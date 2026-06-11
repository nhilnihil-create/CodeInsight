#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define pb push_back

int cnt, h, w, N;
vector<int> a;


int main()
{
	cin >> h >> w;
  cin >> N;
  a.resize(N);

  rep(i, N){
    cin >> a[i];
  }
  int c[h][w];

  int k = 1;
	for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      c[i][j] = k;
      a[k-1]--;
      if(a[k-1] == 0) k++;
    }
    i++;
    if(i == h) break;
    for(int j = w-1; j >=0; j--){
      c[i][j] = k;
      a[k-1]--;
      if(a[k-1] == 0) k++;
    }
  }
	
  rep(i, h){
    rep(j, w){
      cout << c[i][j] << " ";
    }
    cout << endl;
  }
			  	
	return 0;
}
