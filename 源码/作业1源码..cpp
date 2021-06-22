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
struct Edge {
	int u, v, w;
	Edge() {};
	Edge(int u, int v, int w) :u(u), v(v), w(w) {};
	bool operator<(const Edge& a) {
		return w < a.w;
	}
}edge[110];
int n, m;
int fa[110];
void init() {
	for (int i = 1; i <= m; ++i)fa[i] = i;
}
int find(int x) {
	return fa[x] == x ? x : find(fa[x]);
}
int uni(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx != fy) {
		fa[fx] = fy;
		return 1;
	}
	return 0;
}
int kruskal() {
	int ans = 0;
	init();
	sort(edge + 1, edge + 1 + n);
	for (int i = 1; i <= n; ++i) {
		if (uni(edge[i].u, edge[i].v))
			ans += edge[i].w;
	}
	return ans;
}
signed main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edge[i] = Edge(u, v, w);
	}
	printf("%d\n", kruskal());
	return 0;
}

