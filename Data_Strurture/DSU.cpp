struct DSU {
  vector<int> p, sz;
  int n;
  vector<pair<int, int>> ops;
  int t;

  DSU(int _n): n(_n) {
    p.resize(n);
    sz.resize(n);
    for (int i = 0; i < n; i++) p[i] = i, sz[i] = 1;
    t = 0;
  }
  int find(int x) {
    if (p[x] == x) return x;
    else return p[x] = find(p[x]);
  }
  void unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;
    if (sz[x] > sz[y]) swap(x, y);
    
    ops.emplace_back(x, p[x]);
    p[x] = y;
    ops.emplace_back(~y, sz[y]); 
    sz[y] += sz[x];
    
  }
  void save(){
    t = ops.size();
  }
  void rollback(){
    while ((int)ops.size() > t){
      int i = ops.back().first;
      int j = ops.back().second;
      ops.pop_back();
      if (i >= 0){  
        p[i] = j;
      }else{
        sz[~i] = j;
      }
    }
  }
};