    #include <iostream>
    #include <cstdlib>
    #include <cstring>
    #include <cstdio>
    #include <algorithm>
     
    using namespace std;
     
    const int N = 100010;
     
    int a[N];
     
    int main()
    {	int n;
    	scanf("%d", &n);
    	int Max = 0;
    	for (int i = 1; i <= n; i++)
    		scanf("%d", &a[i]);
    	sort(a + 1, a + 1 + n, greater<int>());
    	int p = 1;
    	while (p <= n && p <= a[p])
    		p++;
    	p--;
    	int x = 1;
    	while (p+x <= n && a[p+x] == p)
    		x++;
    	x--;
    	if (((a[p]-p) & 1) || (x & 1))
    		puts("First");
    	else
    		puts("Second");
    	return 0;
    }