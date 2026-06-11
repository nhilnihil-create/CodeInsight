#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N; 
    int l; 
    int r;
    int data;

    cin >> N;

    int i;
    i = 0;

    while(i < N)
{
    cin >> l;
    cin >> r;
    data += r- l + 1;
    i++;
}
    cout << data << endl;
}