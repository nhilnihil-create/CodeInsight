#include <bits/stdc++.h>
using namespace std;

int N;
int a[100010];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    sort(a, a + N);

    int cnt = 0;
    for (int i = 0; i < N;)
    {
        int x = a[i];
        int c = 0;
        while(a[i]== x && i<N){
            i++;
            c++;
        }
        cnt += c%2;
    }

    cout << cnt << endl;

    return 0;
}
