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

  sparrow::IntColumn p4(inp);
  p4.DropZero();
  std::cout << p4;
  
  sparrow::AverageResult toPrint = p4.Average();
  if (!toPrint.ok) {
    std::cout << "Avg:: failed";
  } else {
    std::cout << "Avg: " << toPrint.value;
  }
}
