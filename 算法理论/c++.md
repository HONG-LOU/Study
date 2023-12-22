<font size=4 face="楷体">

<br>
<br>
<br>

## $\mathcal{C++ ~~~ FOR~~ ALGORITHM ~~~ BY ~~~ HONG-LOU ~~} $

$$ \mathbb{[~2023.11.27~]} $$

<br>

### $C++$ 入门 $($ 仅供算法 $)$😆
<br>


### $~~~~~$ 学习任何一门编程语言，绝不仅仅是学习语法，要了解该语言的使用环境和优缺点，通过学习数据结构，实现数据结构和算法的结合

### $~~~~~ （$程序 $=$ 数据结构 + 算法$)$，这也就是为什么你通常会看到算法这两个字通常和数据结构成对出现。
<br>


### $Introduce$

$~~~~$ $C++$ 是在 $C$ 语言基础上开发的一种集面向对象编程、泛型编程和过程化编程与一体的编程语言，是 $C$ 语言的超集，即 $C \subset C++$

<br>

#### $Header ~~ File$
``` c++
#include <bits/stdc++.h>
```



<br>

#### $Input ~~ \& ~~ Output$

$Input \Downarrow $
``` c++
#include <stdio.h>


```

$~~~~$ 兄弟, 蠢不蠢啊......

$~~~~$ 搜索算法的特点在于, 把将要搜索的目标分成若干层, 每层状态取决于前面几层的状态, 直接达到目标状态.

$~~~~$ 我们将问题分层, 第$i$层决定$a_i$, 我们需要记录三个状态变量: $n - \sum_{j = 1}^ia_j$, 表示后面所有正整数的和, 以及$a_{i - 1}$表示前一层的正整数, 以保证正整数递增, 以及$i$, 确保我们最多输出$m$个正整数.

#### 代码奉上:
``` c++
int m, arr[103];  // arr 用于记录方案

void dfs(int n, int i, int a) {
  if (n == 0) {
    for (int j = 1; j <= i - 1; ++j) printf("%d ", arr[j]);
    printf("\n");
  }
  if (i <= m) {
    for (int j = a; j <= n; ++j) {
      arr[i] = j;
      dfs(n - j, i + 1, j);  // 请仔细思考该行含义。
    }
  }
}

// 主函数
scanf("%d%d", &n, &m);
dfs(n, 1, 1);
```
### 例题 $\mathcal{2}$

$~~~~$ 输入一个正整数, 输出$1\to n$ 的全排列, 按字典序输出.

#### 兄弟, 不要给我说什么 $std::next\_permutation$

$~~~~$ 既然是按字典序输出, 那就应该从最小数开始搜索, 将 $1$ 作为第一层往下枚举, 按顺序, 搜完当前状态下的所有可能, 然后在当前状态中记录层数, 接下来的层中, 就不应该再对前面几层记录的值进行搜索, 当层数为尽头时, 就应该输出此时已记录的值, 并回溯, 将已标记的状态变量复原.

#### 代码奉上, 第一次自己写出来, 虽然很简单, 但还是挺牛逼的.
``` c++
/**
 *    author:  HONG-LOU
 *    created: 2022-09-01 22:58:17
**/
#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> val(n); // 用来存数
  std::vector<bool> used(n, false); // 用来记录当前层之前的状态
  std::function<void()> print = [&] () {
    for(int i = 0; i < n; i++) {
      std::cout << val[i] << " \n"[i == n - 1];
    }
  };  // 输出函数
  std::function<void(int)> dfs = [&] (int x) {
    if(x == n - 1) { // 检测到边界, 输出结束
      print();
    }
    for(int i = 0; i < n; i++) {
      if(!used[i]) {
        used[i] = true; // 记录当前层的选择
        val[x + 1] = i + 1; // 记录值(之前层还未选)
        dfs(x + 1); // 向下继续搜索
        used[i] = false; // 回溯
      }
    }
  }; // Dfs
  dfs(-1); // 因为下标从0开始了, 所以从-1开始搜
  return 0;
}
```

### 完结撒花 $!~!$