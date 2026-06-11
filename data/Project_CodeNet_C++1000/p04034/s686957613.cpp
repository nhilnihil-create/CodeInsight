#include <iostream>

using namespace std;

#define MAX_N 100010
short int num[MAX_N];
bool red[MAX_N];
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int i;
    for(i = 0; i < n; ++i){
        num[i] = 1;
    }
    red[0] = true;
    while(--m >= 0){
        int a, b;
        cin >> a >> b;
        red[b - 1] |= red[a - 1];
        --num[a - 1];
        ++num[b - 1];
        if(num[a - 1] == 0){
            red[a - 1] = false;
        }
    }
    int counts = 0;
    for(i = 0; i < n; ++i){
        counts += red[i];
    }
    cout << counts << '\n';
    return 0;
}
