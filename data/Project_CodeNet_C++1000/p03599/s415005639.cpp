#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath> 

using namespace std;

int main() {
    int A, B, C, D, E, F;
    
    cin >> A >> B >> C >> D >> E >> F;

    int best_solution = 100 * A, best_solute = 0;

    int solution, solute, solvent;

    for (int i = 0; i * 100 * A <= F; i++) {
        for (int j = 0; i * 100 * A + j * 100 * B <= F; j++) {
            solvent = i * 100 * A + j * 100 * B;
            for (int k = 0; solvent + k * C <= F; k++) {
                for (int l = (F - solvent - k * C) / D; l >= 0; l--) {
                    solute = k * C + l * D;
                    solution = solute + solvent;
                    if (100 * solute > solvent * E) continue;
                    if (solute * best_solution > best_solute * solution) {
                        best_solution = solution;
                        best_solute = solute;
                    }
                    break;
                }
            }

        }
    }

    cout << best_solution << " " << best_solute << endl;
    return 0;
}