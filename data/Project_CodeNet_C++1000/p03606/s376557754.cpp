#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main(){

int N;
cin >> N;
vector<vector<int>> seat(N, vector<int>(2));
for (int i = 0; i < N; i++){
     for (int j = 0; j < 2; j++){
          cin >> seat.at(i).at(j);
     }
}

int people = 0;

for (int i = 0; i < N; i++){
     people += seat.at(i).at(1) - seat.at(i).at(0) + 1;
}

cout << people << endl;

return 0;
}