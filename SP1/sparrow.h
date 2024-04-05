#include <bitset>
#include<vector>

namespace sparrow {
  namespace warmup{
    unsigned CountBits(std::bitset<32> bits, unsigned pos, unsigned len);
    unsigned CountBits(std::vector<std::bitset<32>> bits);
    std::pair<std::vector<std::bitset<32>>, bool> BitAnd(std::vector<std::bitset<32>> a, std::vector<std::bitset<32>> b);
  }
}
