#include <iostream>

using namespace std;

int n;
int a, b, c;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int i;
    for(i = 0; i < n; ++i){
        int v;
        cin >> v;
        v %= 4;
        if(v == 0){
            ++a;
        }
        else if(v == 2){
            ++b;
        }
        else{
            ++c;
        }
    }
    if(a >= c || (b == 0 && a >= c - 1)){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
    return 0;
}
