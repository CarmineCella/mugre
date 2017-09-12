// mugre.cpp
// 

#include "miniexp.h"

#include <stdexcept>
#include <iostream>
#include <fstream>

using namespace std;

void grep (const string& filename, char* regex) {
	ifstream in (filename.c_str ());
	if (!in.good ()) {
		cout << "warning: cannot open " << filename << endl;
		return;
	}
	int linum = 1;
	while (!in.eof ()) {
		string line;
		getline (in, line);
		if (miniexp::match (regex, (char*) line.c_str ())) {
			cout << linum << ": " << line << endl;
		}
		++linum;
	}
}
int main (int argc, char* argv[]) {
	try {
        if (argc < 3) {
			throw runtime_error ("syntax is 'mugre regex file1 file2...");
		} else {
			for (unsigned i = 2; i < argc; ++i) {
				grep (argv[i], argv[1]);
			}
		}

	}
	catch (exception& e) {
		cout << "Error: " << e.what () << endl;
	}
	catch (...) {
		cout << "Fatal error: unknown exception" << endl;
	}
	return 0;
}

// EOF

