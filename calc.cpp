/**
 *    author:  HONG-LOU
 *    created: 2023-02-15 15:23:14
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  freopen("result.txt", "r", stdin);
  double sum = 0;
  double ave = 0; //
  for (int i = 0; i < 36; i++) {
    double x, y;
    std::string s;
    std::cin >> s;
    std::cin >> x >> y;
    ave += x * y;
    sum += y;
  }
  printf("%.6f", ave / sum);
  return 0;
}
