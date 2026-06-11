#include<iostream>
using namespace std;

int N;

int main(){
    cin >> N;
    int max_count = 0;
    int result = 1;
    for (int i = 1; i < N + 1; i++)
    {
        int count = 0;
        int n = i;
        // cout << i << endl;
        /* code */
        while(true){
            // cout << n << endl;
            if (n % 2 == 0 && n > 0)
            {
                n /= 2;
                count++;
            }
            else{
                break;
            }   
        }
        if (count > max_count)
        {
            max_count = count;
            result = i;
            /* code */
        }
    }
    cout << result << endl;
    
}