#include "sparrow.h"
#include <bitset>
#include <vector>
#include <iostream>

int main(){
  std::vector<std::bitset<32>> b1 {std::bitset<32> ("11100000000001100000000000100010")};
  std::vector<std::bitset<32>> b2 {std::bitset<32> ("01110000000001111000000000100001")};

  if(auto [bAnd, ok] = sparrow::warmup::BitAnd(b1, b2); ok){
    std::cout << sparrow::warmup::CountBits(bAnd[0], 0, 32);
  }
}
