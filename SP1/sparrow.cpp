
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
}


