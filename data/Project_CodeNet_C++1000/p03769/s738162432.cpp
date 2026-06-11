    #include <bits/stdc++.h>
     
    #define fr first
    #define sc second
    #define mk make_pair
    #define pb push_back
    #define ll long long
    #define ld long double
    #define OK puts("OK");
    #define sz(s) (int)s.size()
    #define all(s) s.begin(), s.end()
     
    using namespace std;
     
    const int N = 2e5 + 10;
    const int inf = 1e9 + 7;
     
    ll n, cnt;
    deque <int> dq;
     
    void go(ll a)
    {
        if(a == 1)
            return;
        if(a & 1)
        {
            go(a - 1);
            dq.push_front(++ cnt);
            return;
        }
        go(a / 2);
        dq.pb(++ cnt);
    }
     
    main()
    {
        cin >> n;
        go(n + 1);
        cout << 2 * cnt << endl;
        while(!dq.empty())
            cout << dq.front() << " ", dq.pop_front();
        for(int i = 1 ; i <= cnt ; i ++)
            cout << i << " ";
    }