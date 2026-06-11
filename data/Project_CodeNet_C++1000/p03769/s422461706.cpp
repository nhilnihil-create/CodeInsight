#include<bits/stdc++.h>
using namespace std;
deque<int> fr,se;
void solve(int num,long long v){
	if(v==0) return;
	if(v&1){
		solve(num+1,v>>1);
		fr.push_front(num),se.push_front(num);
	}else{
		solve(num+1,v-1);
		fr.push_back(num),se.push_front(num);
	}
}
long long N;
int main(){
    cin>>N;
    solve(1,N);
    printf("%d\n",fr.size()+se.size());
    while(!fr.empty()) printf("%d ",fr.front()),fr.pop_front();
    while(!se.empty()) printf("%d ",se.front()),se.pop_front();
    return 0;
}