
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
    NullableInts* output = new NullableInts();
    output->nums.resize(inputs.size());
    output->valid.resize((inputs.size() + 31) / 32);
    
    for(int i = 0; i < inputs.size(); i++){
      if(inputs[i] == "null")
	output->valid[i/32].set(i%32, false);
      else{
	bool val = true;
        for (char c : inputs[i]) {
	  if (!isdigit(c) && c!='-'){
	    val = false;
	    break;
	  }
	}
	if (val) {
	  output->nums[i] = std::stoi(inputs[i]);
	  output->valid[i / 32].set(i % 32, true);
	} else {
	  output->valid[i / 32].set(i % 32, false);
	}
      }
    }
    return output;
  }

  int NullableIntsToArray(NullableInts& inputs, int** p){
    int count = 0;
    
    for(int i = 0; i < inputs.nums.size(); i++){
      if(inputs.valid[i/32][i%32]){
	count++;
      }
    }

    *p = new int[count];
    int count2 = 0;

    for (int i = 0; i < inputs.nums.size(); i++) {
      if(inputs.valid[i/32][i%32]){
	(*p)[count2] = inputs.nums[i];
	count2++;
      }
    }
    
    return count;
  }
}
