#include <string>
#include <vector>
#include <sstream>


#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

std::vector<int> parseInts(std::string str) {

  std::stringstream ss(str);

  std::vector<int> v;

  const char delim = ' ';

  std::string s;
  while(std::getline(ss, s, delim)) {
    v.push_back(stoi(s));
  }

  return v;
}




#endif // UTILS_H_INCLUDED
