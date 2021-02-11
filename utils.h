#include <string>
#include <vector>
#include <sstream>
#include <tuple>


#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

typedef std::pair<int,int> EdgeVec;


// old version of parsing edges
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



// parses "2 3" to the pair (2, 3)
EdgeVec parseEdge(std::string str) {

  std::stringstream ss(str);

  std::string s;

  const char delim = ' ';

  std::getline(ss, s, delim);

  int a = stoi(s);

  std::getline(ss, s, delim);

  int b = stoi(s);

  return EdgeVec(a,b);

}




#endif // UTILS_H_INCLUDED
