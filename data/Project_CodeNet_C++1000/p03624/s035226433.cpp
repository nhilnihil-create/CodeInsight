    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        string x; cin >> x;
        sort(x.begin(), x.end());
        for (char i = 'a'; i <= 'z'; ++i) {
            if (!binary_search(x.begin(), x.end(), i))
                return cout << i, 0;
        }
        cout << "None";
        return 0;
    }



