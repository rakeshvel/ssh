#include "sparrow.h"
#include <bitset>
#include <vector>
#include <iostream>

using std::vector;
using std::bitset;


int main(int argc, char *argv[]){
  std::vector<std::string> inp(argc - 1);

  for(int i = 1; i < argc; i++){
    inp[i - 1] = argv[i];
  }
  
  sparrow::NullableInts* convert = sparrow::StrsToNullableInts(inp);
  sparrow::AverageResult toPrint = sparrow::Average(convert);
  if (!toPrint.ok) {
    std::cout << "failed";
  } else {
    std::cout << toPrint.value;
  }
  delete convert;
}
