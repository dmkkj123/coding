#include<bits/stdc++.h>
using namespace std;

int n;
struct node{
	int a,b;
};
vector<node> d;
bool cmp(node x,node y){
	return x.b < y.b;
}
bool check(int mid){
	int mr = 0;
	vector<node> temp(d);
	while(1){
		int flag = 0;
		for(int i = 0; i < temp.size(); ++i){
			int na = temp[i].a;
			int nb = temp[i].b;
			int len = nb-na;
			if(mr >= na - mid && mr <= nb + mid){
				flag = 1;
				if(na + mid >= mr) mr += len;
				else mr = nb + mid;
				temp.erase(temp.begin() + i);
				break;
			}
		}
		if(mr >= 2e4 || !flag) break;
	}
	return mr >= 2e4;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i){
		int a,b;
		cin >> a >> b;
		d.push_back({a * 2, b * 2});
	}
	int l = 0;
	int r = 2e4;
	sort(d.begin(),d.end(),cmp);
	while(l < r){
		int mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	double ans = (double)l / 2.0;
	printf("%.lf\n", ans);
	return 0;
}
