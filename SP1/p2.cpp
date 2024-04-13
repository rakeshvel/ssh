#include "sparrow.h"
#include <bitset>
#include <vector>
#include <iostream>

int main(){
  struct NullableInts nints1{.nums={20,999,40,60}, .valid=vector{bitset<32>{"00000000000000000000000000001101"}}};
  struct NullableInts nints2{.nums={10,10,0,20}, .valid=vector{bitset<32>{"00000000000000000000000000001111"}}};

  struct DivideResult x = sparrow::Divide(&nints1, &nints2);
  std::cout <<sparrow::Average(&DivideResult.value);
}
