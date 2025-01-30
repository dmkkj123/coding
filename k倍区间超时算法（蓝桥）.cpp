#include<bits/stdc++.h>
using namespace std;

int n,k;
int ans = 0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);// 快速写法
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}/*另一种写法 
	for(auto & x : a){ 
		cin >> x; 注意&的存在使得直接改变a本身而不是他的拷贝
	}*/
	int sum;
	for(int i = 0; i < n; ++i){
		sum = 0; // 注意重置
		for(int j = i; j < n; ++j){
			sum += a[j];
			if(sum % k == 0) ans++;
		}
	}
	cout << ans << endl;
	
	return 0;
}
