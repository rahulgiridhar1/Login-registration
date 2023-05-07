#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

fstream file;

class reg {
	private:
		string user;
		string pw;

	public:
		void write() {
			
			file.open("login.txt", ios::app);
			file << "username: "<< user << endl;
			file << "password: " << pw << endl;
			file.close();
		}
		void userInput(string name) {
			user = name;
		}
		void pwInput(string pass) {
			pw = pass;
		}
		void sortAlp() {
			string word;
			vector<vector<string>> names;
			vector<string> usernamesOnly;
			file.open("login.txt", ios::trunc);
			int denom = 0;
			vector <string> names1;
			while (file >> word) {
				string user = word;

				denom++;
				if (word != "username:" && word != "password:") {



					names1.push_back(word);

				}
				if (denom % 4 == 0) {
					names.push_back(names1);
					names1.clear();
				}


			}

			for (size_t k = 0; k < names.size(); k++) {
				usernamesOnly.push_back(names[k][0]);

			}

			sort(usernamesOnly.begin(), usernamesOnly.end());

			/*for (int j = 0; j < usernamesOnly.size(); j++) {
				cout << usernamesOnly[j] << endl;
			}
			*/
			int value = 0;
			//int value1 = 0;
			int num = 0;
			for (size_t i = 0; i < names.size(); i++) {
				file << "username: " << usernamesOnly[i] << endl;
				for (size_t j = 0; j < names.size(); j++) {
					if (names[num][0] == usernamesOnly[i]) {
						file << "password: " << names[num][1] << endl;
						break;
					}
					num++;
					//value1++;
				}
				num = 0;
				//value++;
			}

			file.close();
		}
};

class login {
private:
	string user2;
	string pw2;
	bool U = false;;
	bool P = true;
public:
	void storeUser(string username) {
		file.open("login.txt");
		while (file >> user2) {
			//cout << user2 << endl;
			if (user2 == username) {
				U = true;
				break;
			}
			else {
				U = false;
			}
			
		}
		file.close();
		
	}
	void storePw(string password) {
		file.open("login.txt");
		while (file >> pw2) {
			if (pw2 == password) {
				P = true;
				break;
			}
			else {
				P = false;
			}
		}
		file.close();
	}
	bool check() {
		if (U == true && P == true) {
			//cout << "Login succesful" << endl;
			return true;
		}
		else {
			//cout << "Login invalid" << endl;
			return false;
		}
	}
	int forgot() {
		int number;
		cout << "Type 1 to find your password, 0 to exit" << endl;
		cin >> number;
		if (number == 1) {
			string user;
			cout << "Type in username" << endl;
			cin >> user;
			string word;
			vector<vector<string>> names;
			vector<string> usernamesOnly;
			fstream d("login.txt");
			int denom = 0;
			vector <string> names1;
			while (d >> word) {
				string user = word;

				denom++;
				if (word != "username:" && word != "password:") {



					names1.push_back(word);

				}
				if (denom % 4 == 0) {
					names.push_back(names1);
					names1.clear();
				}


			}
			int cool = 0;
			for (int t = 0; t < names.size(); t++) {
				for (int k = 0; k < names.size(); k++) {
					if (names[k][0] == user) {
						cool++;
						cout << "Your password is " << names[k][1] << endl;
						
						break;
					}
				}
				if (cool == 1) {
					break;
				}
			}
			return 2;
		}
		return 3;
	}
};



int main() {

	int number;

	cout << "Choose 1, login, or 2, register" << endl;
	cin >> number;

	if (number == 2) {
		string username;
		string password;
		cout << "Type in username" << endl;
		cin >> username;
		cout << "Type in password" << endl;
		cin >> password;
		reg Obj;
		Obj.userInput(username);
		Obj.pwInput(password);
		Obj.write();
		Obj.sortAlp();
		cout << "Registration succesful" << endl;
	}

	if (number == 1) {
		int val = 0;
		string username1;
		string password1;
		while (val == 0) {
			cout << "Type in username" << endl;
			cin >> username1;
			cout << "Type in password" << endl;
			cin >> password1;

			login Obj;
			Obj.storeUser(username1);
			Obj.storePw(password1);
			Obj.check();
			if (Obj.check() == true) {
				cout << "Login succesful" << endl;
				cout << "Type 1 to continue" << endl;
				cin >> val;
			}
			else {
				int g;
				cout << "Login invalid" << endl;
				cout << "Click 2 to see forgotten password, 0 to retry" << endl;
				cin >> g;
				if (g == 2) {
					Obj.forgot();
					//cin >> g;
					if (Obj.forgot() == 3) {
						val = 1;
						break;
					}
					else {
						cout << "Re-login" << endl;
						val = 0;
					}
				}
				if (g == 0) {
					//cout << "Type 0 to retry" << endl;
					//cin >> val;
					continue;
				}
			}
		}

		//sortAlp();
	}
}
