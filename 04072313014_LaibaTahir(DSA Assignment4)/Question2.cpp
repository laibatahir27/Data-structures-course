#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <cctype>
#include <map>

int main(int argc, char*argv[]) {
	std::set<std::string> s;
	std::set<std::string>::iterator set_it;
	std::map<std::string, int> m;
	std::map<std::string, int>::iterator map_it;

	std::string file_name;
	if (argc == 1) {
		std::cout << "No command line argument has passed!" << std::endl;
		std::cout << "Enter file name" << std::endl;
		std::getline(std::cin, file_name);

	}
	else {
		file_name = argv[1];
	}

	// read stop words
	std::ifstream infile("stop.txt");
	if (!infile) {
		std::cout << "Stop words file not opening" << std::endl;
		return 1;
	}

	std::string word;
	while (infile.good()) {
		infile >> word;
		s.insert(word);  // Insert stop words into the set
	}
	infile.close();

	set_it = s.begin();
	// Display the stop words
	std::cout << "\nStop words:" << std::endl;
	while (set_it != s.end()) {
		std::cout << *set_it << std::endl;
		set_it++;
	}

	//read frequent words
	infile.open("frequent.txt");
	if (!infile) {
		std::cout << "Frequent words file not opening" << std::endl;
		return 1;
	}

	while (infile.good()) {
		infile >> word;
		std::string newword;
		for (char& c : word) { // Convert word to lowercase
			if (!std::ispunct(c)) {
				newword += tolower(c);
			}
			//c = tolower(c);
		}
		word = newword;
		if (s.find(word) == s.end()) {  // if word does not exist in the tree(set)
			map_it = m.find(word);  // checq if word exists in tree(map)
			if (map_it == m.end()) {  // if word not exists in tree(map)insert it
				m.insert({ word, 1 });
			}
			else {
				map_it->second++;
			}
		}
	}
	infile.close();

	std::ofstream outfile;
	outfile.open(file_name, std::ios::out);
	if (!outfile) {
		std::cout << "File not opened";
		return 1;
	}
	map_it = m.begin();
	while (map_it != m.end()) {
		outfile << map_it->first << ": " << map_it->second << std::endl;
		map_it++;
	}
	outfile.close();

	map_it = m.begin();
	// Display the word counts
	std::cout << "Word Frequencies:" << std::endl;
	while (map_it != m.end()) {
		std::cout << map_it->first << ": " << map_it->second << std::endl;
		map_it++;
	}

	std::ofstream f("map.html");
	if (!f) {
		std::cout << "HTML file could not be opened" << std::endl;
		return 1;
	}

	f << "<html>";
	f << "<body>\n";
	map_it = m.begin();
	while (map_it != m.end()) {
		f << "<font size=\"" << map_it->second << "\">" << map_it->first << "</font>\n";
		++map_it;
	}
	f << "</body>";
	f << "</html>";
}
