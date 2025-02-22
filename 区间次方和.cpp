#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 4; // 定义最大数组长度
const ll M = 1e9 + 7; // 取模常数，防止溢出

// **快速幂（Exponentiation by Squaring）**
// 计算 a^k % M，时间复杂度 O(log k)
ll fast_power(ll base, int exp, ll mod) {
    ll res = 1; // 结果初始化为 1
    base %= mod; // 先取模，避免后续计算中溢出

    while (exp) { // 直到 exp 变为 0
        if (exp & 1) res = res * base % mod; // 如果 exp 的最低位是 1，则乘 base
        base = base * base % mod; // base 平方取模，减少计算量
        exp >>= 1; // 右移一位，相当于 exp /= 2
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m; // 读取 n 和 m

    vector<ll> a(n + 1, 0); // 存储数组 a，下标从 1 开始
    vector<vector<ll>> prefixSum(6, vector<ll>(n + 1, 0)); // 存储 k=1~5 的前缀和

    // **读取数组并预计算 k 次方前缀和**
    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; // 读取 a[i]
        for (int k = 1; k <= 5; ++k) { // 计算 a[i] 的 k 次方
            ll power_val = fast_power(a[i], k, M); // 计算 a[i]^k % M
            prefixSum[k][i] = (prefixSum[k][i - 1] + power_val) % M; // 计算前缀和，取模
        }
    }

    // **处理查询**
    while (m--) {
        int l, r, k;
        cin >> l >> r >> k; // 读取查询参数
        ll ans = (prefixSum[k][r] - prefixSum[k][l - 1] + M) % M; // 计算区间和，防止负数
        cout << ans << '\n';
    }

    return 0;
}
