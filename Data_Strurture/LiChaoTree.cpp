const int maxc = 1e6 + 10;
namespace lichao {
	struct line {
		long long a, b;
		line() : a(0), b(0) {}
		line(long long a, long long b) : a(a), b(b) {}
		long long operator()(int x) const { return a * x + b; }
	};
	line st[maxc * 4];
	int sz;
	void init() {
		sz = 0;
	}
	void add(int l, int r, line tl, int o) {
		bool lcp = st[o](l) > tl(l);
		bool mcp = st[o]((l + r) / 2) > tl((l + r) / 2);
		if (mcp) swap(st[o], tl);
		if (r - l == 1) return;
		if (lcp != mcp) {
			add(l, (l + r) / 2, tl, 2 * o + 1);
		}
		else {
			add((l + r) / 2, r, tl, 2 * o + 2);;
		}
	}
	long long query(int l, int r, int x, int o) {
		if (r - l == 1) return st[o](x);
		if (x < (l + r) / 2) {
			return min(st[o](x), query(l, (l + r) / 2, x, 2 * o + 1));
		}
		else {
			return min(st[o](x), query((l + r) / 2, r, x, 2 * o + 2));
		}
	}
}