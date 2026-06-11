#include <iostream>

using namespace std;

typedef long long ll;

double eps = 1e-9;

int main()	{
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  double max_density = -10.0;
  int max_density_mass = 0;
  int max_density_sugar_mass = 0;
  int sum_water = 0;
  int sum_sugar = 0;
  for (int i = 0; i < 31; i++)	{
    for (int j = 0; j < 31; j++)	{
      for (int k = 0; k < f - (100*(a*i + b*j)); k++)	{
        for (int l = 0; l < f - (100*(a*i + b*j)); l++)	{
          sum_water = 100 * (a*i + b*j);
          sum_sugar = k*c + l*d;
          if (sum_water + sum_sugar > f || e * (sum_water) < 100 * sum_sugar)	{
            continue;
          }
          /*if (sum_water == 0)	{
            continue;
          }*/
          double density = (100.0 * sum_sugar) / (sum_water + sum_sugar);
          if (density > max_density + eps)	{
            max_density = density;
            max_density_mass = sum_sugar + sum_water;
            max_density_sugar_mass = sum_sugar;
          }
        }
      }
    }
  }
  cout << max_density_mass << " " << max_density_sugar_mass << endl;
  return 0;
}