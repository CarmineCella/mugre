// mugre.cpp
// 

#include "miniexp.h"
#include "tests.h"

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <stdexcept>

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
			cout << filename << ", " << linum << ": " << line << endl;
		}
		++linum;
	}
}
int main (int argc, char* argv[]) {
    say_hello ();
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

