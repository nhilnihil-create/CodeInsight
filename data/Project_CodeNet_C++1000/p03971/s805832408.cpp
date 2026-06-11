#include<iostream>
using namespace std;

int N, A, B;
char S[100000];
int pass = 0;
int pass_abroad = 0;

int main(){
    cin >> N >> A >> B;
    // for (int i = 0; i < N; i++)
    // {
        
    //     /* code */
    // }

    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
        if (S[i] == 'a')
        {
            if(pass < A + B){
                pass++;
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
        else if (S[i] == 'b'){
            if(pass < A + B && pass_abroad < B){
                pass++;
                pass_abroad++;
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else{
            cout << "No" << endl;
        }

        /* code */
    }
    
}