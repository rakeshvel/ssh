#include "sparrow.h"
#include <bitset>
#include <vector>
#include <iostream>

using std::vector;
using std::bitset;

int main(int argc, char *argv[]){
  std::vector<std::string> inp(argc);

  for(int i = 0; i < argc; i++){
    inp[i] = argv[i];
  }
  
  sparrow::NullableInts* convert = sparrow::StrsToNullableInts(inp);
  sparrow::AverageResult toPrint = sparrow::Average(convert);
  std::cout << toPrint.value;
}
