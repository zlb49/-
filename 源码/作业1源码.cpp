#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iomanip>
#include<map>
#include<vector>
#include<list>
#include<deque>
#include<stack>
#include<queue>
#include<set>
#include<cctype>
#include<string>
#include<stdexcept>
#include<fstream>
#include<sstream>
#include<sstream>
#define mem(a,b) memset(a,b,sizeof(a))
#define debug() puts("what the fuck!")
#define dedebug() puts("what the fuck!!!")
#define ll long long
#define ull unsigned long long
#define speed {ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); };
using namespace std;
const double PI = acos(-1.0);
const int maxn = 2e5 + 10;
const int N = 2e3 + 10;
const ll INF = 1e18;
const ll mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const double esp_0 = 1e-6;
const double gold = (1 + sqrt(5)) / 2;
inline int rd() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch>'9') {
		if (ch == '-')f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
ll quick(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b % 2) {
			ans = ans * a % mod;
		}
		b >>= 1;
		a = a * a % mod;
	}
	return ans % mod;
}
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}
int n, m;
int g[110][110];
int dis[110];
int vis[110];
int prim() {
	memset(vis, 0, sizeof vis);//标记数组
	memset(dis, inf, sizeof dis);//最小生成树节点间距离
	dis[1] = 0;
	for (int i = 1; i < m; ++i) {
		int pos = 0;
		for (int j = 1; j <= m; ++j) {
			if (!vis[j] && (pos == 0 || dis[j] < dis[pos]))pos = j;
		}
		vis[pos] = 1;
		for (int j = 1; j <= m; ++j) {
			if (!vis[j])dis[j] = min(dis[j], g[pos][j]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		if (dis[i] == inf)return -1;//如果有一个点的dis值为inf，说明该点被孤立，原图不存在最小生成树
		ans += dis[i];
	}
	return ans;//返回权值和
}
signed main() {
	scanf("%d%d", &n, &m);
	memset(g, inf, sizeof g);
	for (int i = 1; i <= n; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u][v] = g[v][u] = w;
	}
	int ans = prim();
	cout << ans << endl;
	return 0;
}

