
Anti Nim (取走最後一個石子者敗)

先手必勝 if and only if
1. 「所有」堆的石子數都是 1 且賽局的 SG 值是 0。
2. 「有些」堆的石子數大於 1 且賽局的 SG 值不是 0。

-------------------------------------------------------

Anti-SG (選擇集合是空的人贏)

定義 SG 值是 0 時，結束，
則先手必勝 if and only if 
1. 賽局中沒有單一賽局的 SG 函數大於 1 且賽局的 SG 函數是 0。
2. 賽局中某個單一賽局的 SG 函數大於 1 且賽局的 SG 函數不是 0。

-------------------------------------------------------
Sprague-Grundy

1. 雙人、回合制
2. 資訊完全公開
3. 無隨機因素
4. 可在有限步內結束
5. 無和局
6. 雙方可採取的行動相同

SG(S) 的值是 0：後手(P)必勝
不是 0：先手(N)必勝


int mex(set S) {
  // find the min number >= 0 that not in the S
  // e.g. S = {0, 1, 3, 4} mex(S) = 2
}

state = []
int SG(A) {
  if (A not in state) {
    S = sub_states(A)
    if( len(S) > 1 ) state[A] = reduce(operator.xor, [SG(B) for B in S])
    else state[A] = mex(set(SG(B) for B in next_states(A)))
  }
  return state[A]
}