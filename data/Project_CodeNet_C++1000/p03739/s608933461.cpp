#include<bits/stdc++.h>
using namespace std;

/*int check(vector<int> a){
	int time = 0;
	int pre_sum = a.at(0);
	int n = a.size();
	if(a.at(0)<0){
		for(int i = 1; i<n; i++){
			int sum = pre_sum + a.at(i);
			if(i%2==1 && sum <= 0){
				time += abs(sum-1);
				sum = 1;
			}else if (i%2==0 && sum >=0){
				time += abs(sum+1);
				sum = -1;
			}
			pre_sum = sum;
		}
	}else if(a.at(0)>0){
		for(int i = 1; i<n; i++){
			int sum = pre_sum + a.at(i);
			if(i%2==0 && sum <= 0){
				time += abs(sum-1);
				sum = 1;
			}else if(i%2==1 && sum >=0){
				time += abs(sum+1);
				sum = -1;
			}
			pre_sum = sum;
		}
	}
	return time;
}

int zerocheck(vector<int> a){
	a.at(0) = 1;
	int time1 = check(a)+1;
	a.at(0) = -1;
	int time2 = check(a)+1;
	int time = min(time1, time2);
	return time;
}

int main(){
	int n;
	cin >> n;
	int time = 0;
	vector<int> a(n);
	for(auto& x:a){
		cin >> x;
	}
	if(a.at(0) == 0){
		time = zerocheck(a);
	}else{
		time = check(a);
	}
	cout << time << endl;

}*/

int main(){
	int n;
	cin >> n;
	vector<long> a(n);
	for(auto& x: a){
		cin >> x;
	}
	long sum1 = 0;
	long sum2 = 0;
	long time1 = 0;
	long time2 = 0;

	for(int i =0;i<n;i++){
		sum1 += a.at(i);
		sum2 += a.at(i);
		if(i%2 == 0){
			if(sum1<=0){
				time1 += sum1*(-1)+1;
				sum1 = 1;
			}
			if(sum2>=0){
				time2 += sum2+1;
				sum2 = -1;
			}
		}
		if(i%2==1){
			if(sum1>=0){
				time1 += sum1+1;
				sum1 = -1;
			}
			if(sum2<=0){
				time2 += sum2*(-1)+1;
				sum2 = 1;
			}
		}
	}
	cout << min(time1, time2) << endl;

}
