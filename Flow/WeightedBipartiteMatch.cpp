// this is one-indexed
// jobs X workers cost matrix
// cost[i][j] is cost of job i done by worker j
// #jobs must be <= #workers
// Default finds min cost; to find max cost set all costs[i][j] to -costs[i][j]
// O(n^2m)
const ll inf = 2e18;
pair<ll, vector<int>> HungarianMatch(const vector<vector<ll>>& a) {
  int n = a.size()-1;
  int m = a[0].size()-1;
  vector<ll> u(n+1), v(m+1), p(m+1), way(m+1);
  for(int i = 1; i <= n; ++i) {
    p[0] = i;
    int j0 = 0;
    vector<ll> minv(m+1, inf);
    vector<bool> used(m+1, false);
    do {
      used[j0] = true;
      int i0 = p[j0], j1 = -1;
      ll delta = inf;
      for(int j = 1; j <= m; ++j)
        if(!used[j]) {
          ll cur = a[i0][j] - u[i0] - v[j];
          if(cur < minv[j])
            minv[j] = cur, way[j] = j0;
          if(minv[j] < delta)
            delta = minv[j], j1 = j;
        }
      for(int j = 0; j <= m; ++j)
        if(used[j])
          u[p[j]] += delta, v[j] -= delta;
        else
          minv[j] -= delta;
        j0 = j1;
    } while(p[j0] != 0);
    do {
      int j1 = way[j0];
      p[j0] = p[j1];
      j0 = j1;
    } while(j0);
  }

  // For each N, it contains the M it selected
  vector<int> ans(n+1);
  for(int j = 1; j <= m ; ++j)
    ans[p[j]] = j;

  return {-v[0], ans};
}
