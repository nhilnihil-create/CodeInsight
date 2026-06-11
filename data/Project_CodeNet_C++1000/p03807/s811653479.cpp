    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
	int t = 1;
	// cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int x, o = 0;
		while (n--) {
			cin >> x;
			if (x & 1) {
				o++;
			}
		}
		if(o%2==0)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
	}
}
