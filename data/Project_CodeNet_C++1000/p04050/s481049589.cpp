#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int NMAX = 100000 + 5;
const int MMAX = 100 + 5;

int N, M;
int A[NMAX];

int main() {
    ios_base :: sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 1; i <= M; ++ i)
        cin >> A[i];

    int odds = 0;
    for (int i = 1; i <= M; ++ i)
        odds += A[i] % 2;
    
    //More than 2 odds is impossible
    if (odds > 2) {
        cout << "Impossible\n";
        return 0;
    }

    //Odds should come first and last in A
    vector <int> odd_positions;
    for (int i = 1; i <= M; ++ i)
        if (A[i] % 2 == 1)
            odd_positions.push_back(i);
    
    for (int i = 0; i < static_cast <int>(odd_positions.size()); ++ i)
        swap(A[1 + (M - 1) * i], A[odd_positions[i]]);
        
    //Print A
    for (int i = 1; i <= M; ++ i)
        cout << A[i] << " \n"[i == M];
    
    //Build B
    vector <int> B;

    if (A[1] != 1) {
        B.push_back(A[1] - 1);
        A[1] = 1;
    }

    for (int i = 2; i <= M; ++ i) {
        B.push_back(A[i - 1] + 1);
        -- A[i];
    }

    if (A[M] > 0)
        B.push_back(A[M]);
    
    //Print B
    cout << B.size() << '\n';
    for (int i = 0; i < static_cast <int> (B.size()); ++ i)
        cout << B[i] << " \n"[static_cast <unsigned int>(i + 1) == B.size()];
    return 0;
}