
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
  void DropZero(NullableInts* drop){
    for(int i = 0; i < drop->nums.size(); i++){
      if(drop->nums[i]==0)
	drop->valid[i/32].set(i%32, false);
    }
  }

  struct AverageResult Average(const NullableInts* av){
    if(av == nullptr)
      return {0, false};
    int count = 0;
    float total = 0.0;
    for(int i = 0; i < av->nums.size(); i++){
      if(av->valid[i/32][i%32]){
	count++;
	total+=av->nums[i];
      }
    }
    if(count == 0){
      return AverageResult{
	.value=0,
	.ok=false};
    };
    return AverageResult{
      .value=total/count,
      .ok=true};
  }

  struct AverageResult Average(const NullableInts& av){
    return Average(&av);
  }

  struct DivideResult Divide(NullableInts* div1, NullableInts* div2){
    auto [match, check] = sparrow::warmup::BitAnd(div1->valid, div2->valid);
    if(check == false){
      return {{}, false};
    }
    NullableInts output;
    output.nums.resize(div1->nums.size());
    output.valid = match;
    for(int i = 0; i < div1->nums.size(); i++){
    if(div2->nums[i]!=0&&output.valid[i/32][i%32])
      output.nums[i] = div1->nums[i]/div2->nums[i];
    else
      output.valid[i/32].set(i%32, false);
    }
    return DivideResult{
      .value = output,
      .ok = true};
  }

  NullableInts* StrsToNullableInts(std::vector<std::string> inputs){
    NullableInts* output;
    for(int i = 0; i < inputs.size(); i++){
      output->nums[i] = std::stoi(inputs[i]);
      if(inputs[i] == "null")
	output->valid[i/32].set(i%32, false);
      else
	output->valid[i/32].set(i%32, true);
    }
    return output;
  }

  int NullableIntsToArray(NullableInts& inputs, int** p){
    int count = 0;
    int temp[inputs.valid.size()];
    
    for(int i = 0; i < inputs.valid.size(); i++){
      if(inputs.valid[i/32][i%32]){
	temp[count] = inputs.nums[i];
	count++;
      }
    }
    int arr[count];
    int count2 = 0;
    for(auto i : temp){
      arr[count2] = i;
      count2++;
    }
    *p = arr;
    return count;
  }
}
