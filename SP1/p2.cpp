#include "sparrow.h"
#include <bitset>
#include <vector>
#include <iostream>

using std::vector;
using std::bitset;

int main(){
  sparrow::NullableInts nints1{
    .nums={20,999,40,60},
    .valid=vector{bitset<32>{"00000000000000000000000000001101"}}
  };
  sparrow::NullableInts nints2{
    .nums={10,10,0,20},
    .valid=vector{bitset<32>{"00000000000000000000000000001111"}}
  };

  sparrow::DivideResult result = sparrow::Divide(&nints1, &nints2);
  sparrow::AverageResult print = sparrow::Average(&result.nums);
  std::cout << print.value;
}
