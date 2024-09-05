const int maxn = 2e5 + 5;
int u[maxn], v[maxn], w[maxn];
int p[maxn], dep[maxn], sz[maxn], to[maxn];
int tp[maxn], dfn[maxn], tk;
vector<int> g[maxn];

void dfs(int u, int fa) {
    dep[u] = ~fa ? dep[fa] + 1 : 0;
    p[u] = fa;
    sz[u] = 1;
    to[u] = -1;

    for (auto v:g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
        if (to[u] == -1 || sz[v] > sz[to[u]]) swap(to[u], v);
    }
}

void hld(int u, int f) {
    tp[u] = f; dfn[u] = ++tk;
    if (~to[u]) hld(to[u], f);

    for (auto v:g[u]) {
        if (v == p[u] || v == to[u]) continue;
        hld(v, v);
    }
}

vector<pair<int, int>> get(int x, int y) {
  int fx = tp[x], fy = tp[y];
  vector<pair<int, int>> res;
  while (fx != fy) {
    if (dep[fx] < dep[fy]) {
      swap(fx, fy);
      swap(x, y);
    }
    res.emplace_back(dfn[fx], dfn[x]);
    x = p[fx];
    fx = tp[x];
  }
  res.emplace_back(min(dfn[x], dfn[y]), max(dfn[x], dfn[y]));
  int lca = (dep[x] < dep[y] ? x : y);
  return res;
}
