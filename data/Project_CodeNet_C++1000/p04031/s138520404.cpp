#include <iostream>
#include <string>

using namespace std;

int main()
{
  int input_num, num_list[100], cost, min_cost = -1, min_num, max_num;

  cin >> input_num;
  for (int i = 0; i < input_num; i++)
  {
    cin >> num_list[i];
  }

  min_num = max_num = num_list[0];
  for (int i = 0; i < input_num; i++)
  {
    if (min_num > num_list[i]) min_num = num_list[i];
    if (max_num < num_list[i]) max_num = num_list[i];
  }
  for (int j = min_num; j <= max_num; j++)
  {
    cost = 0;
    for (int k = 0; k < input_num; k++)
    {
      cost += (num_list[k] - j) * (num_list[k] - j);
    }
    if (cost < min_cost || min_cost == -1) min_cost = cost;
  }

  cout << min_cost;

  return 0;
}
