    #include <bits/stdc++.h>

    using namespace std;

    int main()
    {
        int n;
        cin >> n;
        int a[n+1];
        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        if(a[1] == a[n]) {
            if(a[1] == n-1 || a[1]*2 <= n) {
                cout << "Yes";
            }
            else {
                cout << "No";
            }
        }
        else if(a[n] - a[1] == 1) {
            int i = 1;
            while(a[i] == a[i+1])
                i ++;
            int j = n - i;
            if(a[1] >= i && 2*(a[n]-i) <= j) {
                cout << "Yes";
            }
            else {
                cout << "No";
            }
        }
        else {
            cout << "No";
        }
        return 0;
    }
