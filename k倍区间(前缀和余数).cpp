#include<bits/stdc++.h>
using namespace std;
using ll = long long;// int : 2e9, double : 9e18
int main(){
	ios::sync_with_stdio(false);
	/*
	1.该语句是为了关闭 C++ 的流与 C 的标准 I/O（如 stdio.h 里的 printf/scanf）
	之间的同步，从而提高 C++ cin/cout 的读写效率。
	2.默认情况下，C++ 和 C 的标准流是同步的，以保证混用 scanf/printf 和 cin/cout 时不会出现混乱。但同步操作会
	带来额外开销，当你只用 C++ 流（cin/cout）时，可以关闭同步以获得性能提升。
	*/
	cin.tie(0);/*
	1,这句是将 cin 与 cout 的绑定解开。默认绑定是为了保证每次你用 cin 读取数据之前，会先把 cout 的缓冲
	刷新一下，以免有残留在缓冲区的内容没输出。
	2.解除绑定后，cin 读数据时就不会自动刷新 cout，因此可能提升一定速度。当然，如果你要调试并实时查看
	输出需要手动输出 endl 或 flush 来刷新。
	3.不需要再写cout.tie(0)
	*/
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	vector<ll> freq(k,0);// k个向量，初始化为0，freq用来储存不同前缀和相同模出现的次数
	ll sum1= 0, ans = 0;
	//数学思想：当两个前缀和的余数相等时，它们之间的子区间和就是 k 的倍数。
	freq[0] = 1;//刚好模是0那么就会直接统计
	for(int i = 0; i < n; ++i){
		sum1 = (sum1+a[i]) % k;//当前前缀和的模
		//if(sum1 < 0) sum1 += k;(如果题目出现负数sum1要加入这句话)
		ans += freq[sum1];
		freq[sum1]++;
	}
	cout << ans << "\n";
	return 0;
}
