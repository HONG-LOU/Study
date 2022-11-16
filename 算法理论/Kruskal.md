<font size=4 face="楷体">

<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>


## $\mathcal{KRUSKAL ~~ ALGORITHM ~~~ BY ~~~ HONG-LOU} $

<br>
<br>
<br>
<br>
<br>


### $Kruskal$ 算法是一种常见并且很好写的最小生成树算法,由 $Kruskal$ 发明. 该算法的基本思想是从小大大加入边, 是个贪心算法.

### 算法虽然简单, 但需要相应的数据结构来支持, 具体来说, 维护一个森岭, 查询两个节点是否在同一棵树中, 连接两棵树.

### 抽象的说, 就是维护一堆集合, 查询两个元素是否属于同一个集合, 合并两个集合.

### 其中, 查询两点是否联通和连接两点可以使用并查集维护.

### 如果使用 $O(m\log m)$ 的排序算法, 并且使用 $O(m\alpha(m, ~n))$ 或 $O(m \log n) $ 的并查集, 就可以得到时间复杂的为 $O(m \log m)$ 的 $Kruskal$ 算法.

<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>


## 证明

### 为了造出一颗最小生成树, 我们从最小边权的边开始, 按边权从小到大依次加入, 如果某次加边产生了环, 就扔掉这条边, 直到加入了 $n - 1$ 条边, 即形成了一棵树.

### 证明: 使用归纳法,证明任何时候$Kruskal$算法选择的边集都被某棵$MST$所包含.

### 基础: 对于算法刚开始时,显然成立（最小生成树存在）。

### 归纳：假设某时刻成立,当前边集为$F$,令$T$为这棵$MST$,考虑下一条加入的边$e$.

### 如果$e$属于$T$,那么成立.

### 否则,$T + e$一定存在一个环，考虑这个环上不属于$F$的另一条边$f$（一定只有一条）.

### 首先,$f$的权值一定不会比$e$小,不然$f$会在$e$之前被选取.

### 然后,$f$的权值一定不会比$e$大,不然$T + e - f$就是一棵比$T$还优的生成树了.

### 所以$T + e - f$包含了$F$,并且也是一棵最小生成树,归纳成立.

## 代码奉上
``` c++
#include <bits/stdc++.h>

struct edge {
  int start, to;
  long long val;
}E[202020];

int f[202020], total;

long long ans;

int find(int x) {
  return x == f[x] ? x : f[x] = find(f[x]);
}

int main() {
  int n, m;
  std::cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    f[i] = i;
  }
  for(int i = 1; i <= m; i++) {
    std::cin >> E[i].start >> E[i].to >> E[i].val;
  }
  std::sort(E + 1, E + m + 1, [&] (edge a, edge b) {
    return a.val < b.val;
  });
  std::function<void()> Kruskal = [&] () {
    for(int i = 1; i <= m; i++) {
      int u = find(E[i].start);
      int v = find(E[i].to);
      if(u == v) {
        continue;
      }
      ans += E[i].val;
      f[u] = v;
      total += 1;
      if(total == n - 1) {
        break;
      }
    }
  };
  Kruskal();
  std::cout << ans << "\n";
  return 0;
}
```
## 完结撒花 $! ~ !$