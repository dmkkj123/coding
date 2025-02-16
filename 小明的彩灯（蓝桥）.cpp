#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 3;
int n, q;
int l, r;
ll x;

void solve(int n, int q){
  vector<ll> a(N, 0);
  vector<ll> d(N, 0);
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
    d[i] = a[i] - a[i - 1];
  }
  for(int i = 1; i <= q; ++i){
    cin >> l >> r >> x;
    d[l] += x;
    d[r + 1] -= x;
  }
  for(int i = 1; i <= n; ++i){
    d[i] += d[i-1];//d[i]之和等于a[i]
    a[i] = d[i];
    if(a[i] < 0){
      a[i] = 0;
    }
  }
  for(int i = 1; i <= n; ++i){
    cout << a[i] << " \n"[i == n];
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> q;
  solve(n, q);
  return 0;
}
