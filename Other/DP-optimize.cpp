Monotonicity & 1D/1D DP & 2D/1D DP
-------------------------------------------------------
Definition xD/yD
1D/1D DP[j] = min(0≤i<j) { DP[i] + w(i, j) }; DP[0] = k
2D/1D DP[i][j] = min(i<k≤j) { DP[i][k - 1] + DP[k][j] } + w(i, j); DP[i][i] = 0
-------------------------------------------------------
Monotonicity
       c       d 
  -----------------
a | w(a, c) w(a, d)
b | w(b, c) w(b, d)

Monge Condition
Concave(凹四邊形不等式): w(a, c) + w(b, d) >= w(a, d) + w(b, c)
Convex (凸四邊形不等式): w(a, c) + w(b, d) <= w(a, d) + w(b, c)

Totally Monotone
Concave(凹單調): w(a, c) <= w(b, d) -----> w(a, d) <= w(b, c)
Convex (凸單調): w(a, c) >= w(b, d) -----> w(a, d) >= w(b, c)
-------------------------------------------------------
1D/1D DP O(n^2) -> O(nlgn)
**CONSIDER THE TRANSITION POINT**
Solve 1D/1D Concave by Stack
Solve 1D/1D Convex by Deque
-------------------------------------------------------
2D/1D Convex DP (Totally Monotone) O(n^3) -> O(n^2)
h(i, j − 1) ≤ h(i, j) ≤ h(i + 1, j)