#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main () {
    using chrono::high_resolution_clock;
    using chrono::duration_cast;
    using chrono::duration;
    using chrono::milliseconds;

    auto t1 = high_resolution_clock::now();

    ifstream file("enwik9");

    if (file.is_open()) {
        string line;
        
        while (getline(file, line)) {
            printf("%s", line.c_str());
        }

        file.close();
    }

    auto t2 = high_resolution_clock::now();
    auto ms_int = duration_cast<milliseconds>(t2 - t1);
    duration<double, milli> ms_double = t2 - t1;

    cout << ms_int.count() << "\nms\n";
    cout << ms_double.count() << "ms\n";

    return 0;
}