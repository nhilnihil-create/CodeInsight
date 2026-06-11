#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int num_of_cells_on_one_side;
  int num_whole_cells;
  int num_black_cells;
  int num_white_cells;
  
  cin >> num_of_cells_on_one_side;
  cin >> num_black_cells;
  num_whole_cells = num_of_cells_on_one_side * num_of_cells_on_one_side;
  num_white_cells = num_whole_cells - num_black_cells;
  
  cout << num_white_cells << endl;
}