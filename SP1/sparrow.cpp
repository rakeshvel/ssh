
#include "sparrow.h"

namespace sparrow{
  namespace warmup{
    unsigned CountBits(std::bitset<32> bits, unsigned pos, unsigned len){
      int count = 0;
      int end = pos + len;
      if(end > 32)
	end = 32;
      while(pos < end){
	if(bits[pos] == 1)
	  count++;
	pos++;
      }
      return count;
    }
    unsigned CountBits(std::vector<std::bitset<32>> bits){
      int count = 0;
      for(std::bitset<32>& bit : bits){
	for (int i = 0; i < 32; i++){
	  if(bit[i] == 1)
	    count++;
	}
      }
      return count;
    }
    std::pair<std::vector<std::bitset<32>>, bool> BitAnd(std::vector<std::bitset<32>> a, std::vector<std::bitset<32>> b){
      if(a.size() != b.size())
	return {std::vector<std::bitset<32>>(), false};

      std::vector<std::bitset<32>> toReturn;

      for(int i = 0; i < a.size(); i++)
	toReturn.push_back(a[i] & b[i]);

      return {toReturn, true};
    }
  }
  struct NullableInts {
    std::vector<int> nums;
    std::vector<std::bitset<32>> valid;
  }
  void DropZero(NullableInts* drop){
    for(int i = 0; i < drop->nums.size(); i++){
      if(drop->nums[1]==0)
	drop->valid[i] = 0;
    }
  }
  struct AverageResult {
    float value;
    bool ok;
  }
  AverageResult Average(NullableInts* av){
    int count = 0;
    auto total = 0.0;
    for(int i = 0; i < av->nums.size(); i++){
      if(av->valid[i]==1){
	count++;
	total+=av->nums[i];
      }
    }
    if(count == 0){
      return AverageResult{
	.value=total,
	.bool=false};
    }
    return AverageResult{
      .value=total,
      .bool=true};
  }
  struct DivideResult{
    NullableInts value;
    bool ok;
  }
  DivideResult Divide(NullableInts* div1, NullableInts* div2){
    std::pair<std::vector<std::bitset<32>> match, bool check = BitAnd(div1->valid, div2->valid);
    if(check == false){
      return DivideResult{
	.value = NullableInts{
	  .nums = nullptr;
	  .valid = nullptr;},
	.ok = false;
    }
    std::vector<int> numbers;
    for(int i = 0; i < div1->nums.size(); i++){
      if((div1->valid[i]==1 || div2->valid[1]==1)&&match[i]==0)
	nums[i] = -1;
      if(match[i]==1)
	nums[1] = div1->nums[i] / div2->nums[i];
    }
    return DivideResult{
      .value = NullableInts{
	.nums=numbers,
	.valid=match},
      .ok = true;}
  }
}
