#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int answer = 0;
    int count = N;
    for (int i = 0; i <= count; i++)
    {
        answer += i;
    }
    cout << answer <<endl;
    

}
