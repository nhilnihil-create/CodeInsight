    //Created Time:2019年12月22日 星期日 21时17分49秒
    #include <iostream>
    #include <cstdio>
    #include <algorithm>
    #include <cstring>
    #define N 100005
     
    using namespace std;
     
    int n, l, t;
    int res[N], b[N], a[N];
     
    int main(){
    	scanf("%d%d%d", &n, &l, &t);
    	int cnt = 0; int r = t % l;
    	for(int i = 1; i <= n; ++i)
    		scanf("%d%d", &a[i], &b[i]), b[i] = b[i] == 1 ? 1 : -1;
    	int p = a[1];
    	for(int i = 1; i <= n; ++i){
    		int x = a[i];
    		a[i] = (a[i] + r * b[i] + l) % l;
    		if(b[i] == b[1]) continue;
    		(cnt += 2 * (t / l) % n) %= n;
    		int dis;
    		if(b[1] < 0) dis = l - x + p;
    		else dis = x - p;
    		if(dis <= r * 2){
    			(++cnt) %= n; dis += l;
    			if(dis <= r * 2) (++cnt) %= n;
    		}
    	}
    	int pos = a[1]; if(!cnt) cnt = n;
    	sort(a + 1, a + 1 + n);
    //	for(int i = 1; i <= n; ++i) cout << a[i] << endl;
    //	return 0;
    	for(int i = b[1] < 0 ? 1 : n; b[1] < 0 ? i <= n : i; b[1] < 0 ? ++i : --i)
    		if(a[i] == pos){
    			pos = i; break;
    		}
     
    //	cout << pos << endl;
    	int j = (1 + b[1] * cnt + n) % n;
    	if(!j) j = n;
    	res[j] = a[pos]; j = j % n + 1;
    	for(int i = pos % n + 1; i != pos; i = i % n + 1, j = j % n + 1)
    		res[j] = a[i];
    	for(int i = 1; i <= n; ++i)
    		printf("%d\n", res[i]);
    	return 0;
    }