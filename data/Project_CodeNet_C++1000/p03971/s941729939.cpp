#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int main()
{
    int N, A, B;
    string S;
    cin >> N >> A >> B;
    cin >> S;
    
    int pass = 0;
    int pass_b = 0;
    
    for(int i=0; i<N; i++) {
        if (S[i] == 'a') {
            if (pass < A + B) {
                cout << "Yes" << endl;
                pass++;
            }
            else {
                cout << "No" <<endl;
            }
        }
        else if (S[i] == 'b') {
            if (pass < A + B) {
                if (pass_b < B) {
                    cout << "Yes" << endl;
                    pass_b++;
                    pass++;
                }
                else {
                    cout << "No" << endl;
                }
            }
            else {
                cout << "No" << endl;
            }
        }
        else {
            cout << "No" << endl;
        }
    }
    
    //cout << S << endl;
    
    //getline(cin, str);
    //vector < vector < int > > A(x, vector(y, 0));
    //int avg = round((float)accumulate(X.begin(), X.end(), 0.0) / N);
    return 0;
}