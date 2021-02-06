#include <iostream>
#include <set>
#include <fstream>
#include <string>
#include "utils.h"

using namespace std;

int main(int argc, char *argv[])
{

    ifstream file(argv[1]);
    string str;

    int num_nodes;
    int num_edges;

    if (getline(file, str)) {
        num_nodes = stoi(str);
    }

    if (getline(file, str)) {
        num_edges = stoi(str);
    }


    cout << "Hello world!" << endl;
    return 0;
}
