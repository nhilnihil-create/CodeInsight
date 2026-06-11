#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int n;
    cin >> n;
    P p[502];
    int b[250002]{0};
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        x--;
        b[x] = i + 1;
        p[i] = P(x, i + 1);
    }
    sort(p, p + n);
    int k = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < p[i].second - 1; j++){
            while(b[k]) k++;
            if(k > p[i].first){
                cout << "No" << endl;
                return 0;
            }
            b[k] = p[i].second;
            k++;
        }
    }
    k = n * n - 1;
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < n - p[i].second; j++){
            while(b[k]) k--;
            if(k < p[i].first){
                cout << "No" << endl;
                return 0;
            }
            b[k] = p[i].second;
            k--;
        }
    }
    cout << "Yes" << endl;
    for(int i = 0; i < n * n; i++) cout << b[i] << " ";
    cout << endl;
}