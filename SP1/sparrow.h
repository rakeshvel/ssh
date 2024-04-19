#include <bitset>
#include<vector>

namespace sparrow {
  namespace warmup{
    unsigned CountBits(std::bitset<32> bits, unsigned pos, unsigned len);
    unsigned CountBits(std::vector<std::bitset<32>> bits);
    std::pair<std::vector<std::bitset<32>>, bool> BitAnd(std::vector<std::bitset<32>> a, std::vector<std::bitset<32>> b);
  }
  struct NullableInts {
    std::vector<int> nums;
    std::vector<std::bitset<32>> valid;
  };
  void DropZero(NullableInts* drop);
  struct AverageResult{
    float value;
    bool ok;
  };
  struct AverageResult Average(const NullableInts* av);
  struct AverageResult Average(const NullableInts& av);
  struct DivideResult{
    NullableInts value;
    bool ok;
  };
  struct DivideResult Divide(NullableInts* div1, NullableInts* div2);
  NullableInts* StrsToNullableInts(std::vector<std::string> inputs);
  int NullableIntsToArray(NullableInts inputs, int** p);
}
