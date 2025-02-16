#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;

int n, m;
int x, y, z;
void solve(int n, int m){
  vector<int> a(N,0);//保证左右都有一个数
  vector<int> d(N,0);//定义差分数组
  for(int i = 1; i <= n; ++i){  
    cin >> a[i];
    d[i] = a[i] - a[i - 1];
  }  
  for(int i = 0; i < m; ++i){
    cin >> x >> y >> z;
    d[x] += z;
    d[y+1] -= z;//在x到y加上z
  }
  for(int i = 1; i <= n; ++i){
    a[i] = d[i] + a[i-1];
  }
  for(int i = 1; i <= n; ++i){
    cout << a[i] << " \n"[i == n];
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  while(cin >> n >> m){
    solve(n, m);
  }

  return 0;
}
