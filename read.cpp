/**
 *    author:  HONG-LOU
 *    created: 2023-02-15 15:23:19
**/
#include <bits/stdc++.h>

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  freopen("score.txt", "r", stdin);
  int sum = 36;
  std::vector<std::pair<std::string, std::pair<double, double>>> x(sum);
  std::string s;
  for (int i = 0; i < sum; i++) {
    std::cin >> s >> s >> s >> x[i].first >> x[i].second.first >> x[i].second.second >> s >> s >> s >> s >> s >> s >> s;
  }
  freopen("result.txt", "w", stdout);
  for (int i = 0; i < sum; i++) {
    std::cout << x[i].first << ' ' << x[i].second.first << ' ' << x[i].second.second;
    if (i < sum - 1) {
      std::cout << "\n";
    }
  }
  return 0;
}