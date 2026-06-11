#include <bits/stdc++.h>
using namespace std;
int A, B, C, D, E, F;

int main()
{
    cin >> A >> B >> C >> D >> E >> F;
    float max = 0.0;
    int max_water = 0;
    int max_sugar = 0;
    for (int i = 0; i * 100 * A <= F; i++)
    {
        for (int j = 0; (i * A + j * B) * 100 <= F; j++)
        {
            int water = (i * A + j * B) * 100;
            for (int k = 0; C * k <= (i * A + j * B) * E; k++)
            {
                
                for (int l = 0; (C * k + D * l) <= (i * A + j * B) * E; l++)
                {
                    
                    int sugar = C * k + D * l;
                    if (sugar + water > F )
                        continue;
                    float noudo;
                    if (sugar <= 0) {
                        noudo = 0;
                    }
                    else {
                        noudo = (100.0 * sugar) / (sugar + water);
                    }
                    if (noudo >= max)
                    {
                        max = noudo;
                        max_water = water;
                        max_sugar = sugar;
                    }
                }
            }
        }
    }
    cout << max_water + max_sugar << " " << max_sugar << endl;
}