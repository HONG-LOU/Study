<font size=4 face="楷体">

#### 题目来源 $~~~ $ 洛谷 P2398

$$\sum_{i = 1}^{n}\sum_{j = 1}^{n}gcd(i, ~j)$$

$\mathcal{SOLUTION}$

$~~~~$ 枚举 $gcd(i, ~j) = x$, 即
$$\sum_{i = 1}^{n}\sum_{j = 1}^{n}\sum_{x = 1}^{n}[gcd(i, ~j) = x] \times x$$

$$=\sum_{i = 1}^{n}\sum_{j = 1}^{n}\sum_{x = 1}^{n}[gcd(i / x, ~j/x) = 1] \times x$$

$$=\sum_{i = 1}^{n}x\times\sum_{j = 1}^{n}\sum_{x = 1}^{n}[gcd(i / x, ~j/x) = 1]$$

$~~~~$ 由欧拉函数定义,$$\varphi(n) = \sum_{i = 1}^{n}[gcd(i, ~n) = 1]$$ 

$~~~~$ 原式化为 $$\sum_{x = 1}^{n} \times ((\sum_{i = 1}^{n / x}2\varphi(i)) - 1)$$
$~~~~$ 有序对乘以$2$, 但$(x, ~x)$只有一次.

$~~~~$ 考虑 $\Theta(n)$ 筛法求 $\varphi$  $$sum(n) = \sum_{i = 1}^n \varphi(i) = sum(n - 1) + \varphi(n)$$

$$\sum_{x = 1}^nx \times (2 sum(n / x) - 1)$$

