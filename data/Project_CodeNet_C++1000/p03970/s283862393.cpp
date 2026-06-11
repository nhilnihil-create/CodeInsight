#include<bits/stdc++.h>
using namespace std;

char a[16], word[16] = {'C', 'O', 'D', 'E', 'F', 'E', 'S', 'T', 'I', 'V', 'A', 'L', '2', '0', '1', '6'};
int answer;

int main()
{
    cin >> a;
    for(int i = 0; i < 16; i ++)
      if(a[i] !=word[i]) 
        answer++;
    cout << answer << "\n";
    return 0;
}