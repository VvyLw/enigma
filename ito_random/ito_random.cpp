#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <numeric>
int main() {
  std::random_device seed_gen;
  std::mt19937 engine{seed_gen()};
  const int front = 1, back = 100, count = 1;
  std::vector<int> v(back), res;
  std::iota(v.begin(), v.end(), front);
#if __cplusplus >= 202100L
  std::ranges::sample(v, back_inserter(res), count, engine);
#else
  std::sample(v.begin(), v.end(), back_inserter(res), count, engine);
#endif
  std::cout << res.front() << '\n';
}
