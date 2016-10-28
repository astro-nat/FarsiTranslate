#include <iostream>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

/* TO DO:

1. Find more efficient way to store Persian dictionary. Text file or SQL database?
2. If word not located in database, translate by letter?
3. Translate paragraphs, not just one word.

*/

typedef vector<tuple<string,string,string>> Maptype;

class SymbolMap {
	private:
		Maptype m;
		int size = 0;
		
	public:
		SymbolMap() {
			insert_into_map("سلام","salaam","hello");
			insert_into_map("ثهتظرئ","chetori","how are you");
			insert_into_map("","bekheir","good");
		}
	
		void insert_into_map(string farsi, string farsglish, string english) {
			m.push_back(make_tuple(farsi,farsglish,english));
			size++;
		}
	
		Maptype getMap() {
			return m;
		}
		
		int getSize() {
			return size;
		}
		
		string FarsitoEnglish(string farsi) {
			for (auto i : m) {
				if (get<0>(i) == farsi) { return get<2>(i); }		
			}
			return "Unknown";
		}
		
		string FarsitoFarsglish(string farsi) {
			for (auto i : m) {
				if (get<0>(i) == farsi) { return get<1>(i); }
			}
			return "Unknown";
		}
		
		string FarsglishtoEnglish(string farsglish) {
			for (auto i : m) {
				if (get<1>(i) == farsglish) { return (get<2>(i)); }
			}
			return "Unknown";
		}
		
		string FarsglishtoFarsi(string farsglish) {
			for (auto i : m) {
				if (get<1>(i) == farsglish) { return get<0>(i); }
			}
			return "Unknown";
		}
				
		string EnglishtoFarsi(string english) {
			for (auto i : m) {
				if (get<2>(i) == english) { return get<0>(i); }
			}
			return "Unknown";
		}
		
		string EnglishtoFarsglish(string english) {
			for (auto i : m) {
				if (get<2>(i) == english) { return get<1>(i); }
			}
			return "Unknown";
		}
		
		
};

int main() {
	SymbolMap sm;
	string input;
	int choice;
	
	while(input != "quit") {
		cout << "---------------" << endl << "Which translator would you like?" << endl << "(1) English to Farsi" << endl << "(2) English to Farsglish" << endl << "(3) Farsi to English" << endl << "(4) Farsi to Farsglish" << endl << "(5) Farsglish to Farsi" << endl << "(6) Farsglish to English" << endl << "---------------" << endl;
		cin >> choice;
	
	switch (choice) {
		case 1:
			cout << "Enter a English phrase: ";
			cin >> input;
			cout << "Translation: " << sm.EnglishtoFarsi(input) << endl;
			break;
		case 2:
			cout << "Enter a English phrase: ";
			cin >> input;
			cout << "Translation: " << sm.EnglishtoFarsglish(input) << endl;
			break;
		case 3:
			cout << "Enter a Farsi phrase: ";
			cin >> input;
			cout << "Translation: " << sm.FarsitoEnglish(input) << endl;
			break;
		case 4:
			cout << "Enter an Farsi phrase: ";
			cin >> input;
			cout << "Translation: " << sm.FarsitoFarsglish(input) << endl;
			break;
		case 5:
			cout << "Enter a Farsglish phrase: ";
			cin >> input;
			cout << "Translation: " << sm.FarsglishtoFarsi(input) << endl;
			break;
		case 6:
			cout << "Enter a Farsglish phrase: ";
			cin >> input;
			cout << "Translation: " << sm.FarsglishtoEnglish(input) << endl;
			break;
		default:
			break;
	}
}
}