#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
using ll = long long;

int n, m;
vector<ll> a(N);

int check(ll mid){
  int res = 1, list = 0;
  for(int i = 0; i < n; ++i){
    if(a[i] - a[list] >= mid){
      res++;
      list = i;
    }
    return res;
  }
}

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  sort(a.begin(), a.begin() + n);// 开到N，从0到n
  ll left = 0, right = a[n - 1] - a[0];
  while(left < right){
    ll mid = (left + right + 1) / 2;
    if(check(mid) >= m) left = mid;// left不能大，只能改变right
    else right = mid - 1;
  } 
  cout >> left >> endl;

  return 0;
}
