#include<iostream>
#include<string>   //string header file
#include<fstream>  // for file handling purpose
#include<iomanip>  //  for input and ouput manipulation
#include<cstring>   // for c-style string ftns i.e.strlen() etc

class Customer {
private:
	int size = 3;
	char id[20];
	char app_type[20];
	char location[20];
	char contact_num[15];

	// Functions declaration
	friend void add_item(Customer&c);
	friend void update_item(Customer&c);
	friend void delete_item(Customer&c);
	friend void search_item(Customer&c);

public:
	Customer() {            // Constructor
		for (int i = 0; i < 20; i++) {
			id[i] = '\0';
		}
		for (int i = 0; i < 20; i++) {
			app_type[i] = '\0';
		}
		for (int i = 0; i < 20; i++) {
			location[i] = '\0';
		}
		for (int i = 0; i < 15; i++) {
			contact_num[i] = '\0';
		}
	}

	// to write in binary file
	void writefile(std::ofstream &outfile) {
		outfile.write((const char*)this, sizeof(Customer));
	}

	// to input record of each customer
	void input() {
		std::cin.ignore();

		std::cout << "Before entering id,you must know that a valid id contains digits 0-9" << std::endl;
		bool valid_id;

		do {
			valid_id = true;
			std::cout << "Please enter a valid id:";
			std::cin.getline(id, 20);

			// to calculate length of id
			int length = strlen(id);
			std::cout << "Length:" << length << std::endl;


			for (int i = 0; i < length; i++) {
				if (!isdigit(id[i])) {
					valid_id = false;
					break;
				}

			}

		} while (!valid_id);
		std::cout << "Thankyou for entering valid id!" << std::endl;
		std::cout << "\n";

		bool valid_app;
		do {
			valid_app = true;
			std::cout << "Please enter valid appointment type(i.e string type):";
			std::cin.getline(app_type, 20);


			int length = strlen(app_type);
			std::cout << "Length:" << length << std::endl;

			for (int i = 0; i < length; i++) {
				if (!islower(app_type[i]) && !isupper(app_type[i])) {
					valid_app = false;
					break;
				}

			}

		} while (!valid_app);
		std::cout << "Thankyou for entering valid appointment type!" << std::endl;
		std::cout << "\n";

		std::cout << "Enter location:";
		std::cin.getline(location, 20);
		std::cout << "\n";

		std::cout << "\n\n";
		std::cout << "Before entering contact number,you must know that a valid contact number contains 0-9 digits." << std::endl;

		bool valid_contact;

		do {
			valid_contact = true;
			std::cout << "Please Enter a valid contact number:";
			std::cin.getline(contact_num, 15);

			int length = strlen(contact_num);
			std::cout << "Length:" << length << std::endl;

			for (int i = 0; i < length; i++) {
				if (!isdigit(contact_num[i])) {
					valid_contact = false;
					break;
				}
				else if (length < 11 || length>11) {
					valid_contact = false;
					break;
				}

			}

		} while (!valid_contact);
		std::cout << "Thankyou for entering valid contact number!" << std::endl;
		std::cout << "\n";
	}

	// to write in csv file
	void write_csv(std::ofstream &outfile) {

		outfile<< id << "," << app_type << ","  << location << ","  << contact_num << std::endl;
		
	}

	//to read from csv file
	void read_csv(std::ifstream &infile) {
		std::string s;
		while (!infile.eof()) {
			std::getline(infile, s, ',');
			std::cout << s << ",";
		}
		
	}

};
                                             // Functions definition

//to add item in a specific record
void add_item(Customer&c) {
	std::string item, item_name;
	std::cout << "Enter item you want to add." << std::endl;
	std::cin.ignore();
	std::getline(std::cin, item);

	std::cout << "Enter your " << item << std::endl;
	std::cin.ignore();
	std::getline(std::cin, item_name);

	std::cout << "Item has added successfully!" << std::endl;


}

//to update item of a specific record
void update_item(Customer&c) {
	std::cin.ignore();

	std::cout << std::setw(60) << "Please update your record!" << std::endl;
	std::cout << "Enter a new id:";
	std::cin.getline(c.id, 20);

	std::cout << "Enter new appointment type(i.e string type):";
	std::cin.getline(c.app_type, 20);

	std::cout << "Enter new location:";
	std::cin.getline(c.location, 20);

	std::cout << "Enter new contact number:";
	std::cin.getline(c.contact_num, 15);

	std::cout << "Your record has updated successfully!" << std::endl;

}

// to delete item of a specific record
void delete_item(Customer&c) {
	char del[15];

	std::cout << "Enter an item you want to delete:" << std::endl;
	std::cin.ignore();
	std::cin.getline(del, 15);
	int l = strlen(del);

	if (strcmp(del, c.id) == 0) {
		for (int i = 0; i < l; i++) {
			c.id[i] = '\0';
		}
		std::cout << "Id is deleted sucessfully:" << c.id << std::endl;
	}

	else if (strcmp(del, c.app_type) == 0) {
		for (int i = 0; i < l; i++) {
			c.app_type[i] = '\0';
		}
		std::cout << "Appointment type is deleted sucessfully:" << c.app_type << std::endl;
	}

	else if (strcmp(del, c.location) == 0) {
		for (int i = 0; i < l; i++) {
			c.location[i] = '\0';
		}
		std::cout << "Location is deleted sucessfully:" << c.location << std::endl;
	}

	else if (strcmp(del, c.contact_num) == 0) {
		for (int i = 0; i < l; i++) {
			c.contact_num[i] = '\0';
		}
		std::cout << "Contact number is deleted sucessfully:" << c.contact_num << std::endl;
	}

	else {
		std::cout << "Sorry! this item does not exists." << std::endl;
	}
}

// to search item from a specific record
void search_item(Customer&c) {
	std::string searching;

	std::cout << "Enter an item you want to search:" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, searching);

	if (searching == c.id) {
		std::cout << "Searched item is:" << c.id << std::endl;
	}

	else if (searching == c.app_type) {
		std::cout << "Searched item is:" << c.app_type << std::endl;
	}

	else if (searching == c.location) {
		std::cout << "Searched item is:" << c.location << std::endl;
	}

	else if (searching == c.contact_num) {
		std::cout << "Searched item is:" << c.contact_num << std::endl;
	}

	else {
		std::cout << "Sorry! this item does not exists." << std::endl;
	}

}

void help() {
	std::cout << "\n\n";
	std::cout << "Thankyou for signing up and inputting the details!" << std::endl;
	std::cout << "Now you have to press any of the option from 1-4 as shown in menu to" << std::endl;
	std::cout << "add, update, delete or to search something." << std::endl;
}

// ftn to check whether password is valid or not
bool valid_password(const std::string& password) {
	if (password.length() < 8) {
		return false; // It must have atleast 8 characters
	}

	bool upper_case = false;
	bool lower_case = false;
	bool digit = false;
	bool special_char = false;

	for (char ch : password) {
		if (islower(ch)) {
			lower_case = true;
		}

		else if (isupper(ch)) {
			upper_case = true;
		}

		else if (isdigit(ch)) {
			digit = true;
		}
		else if (ch == '!' || ch == '@' || ch == '#' || ch == '$' || ch == '%' || ch == '^' || ch == '&' || ch == '*'
			|| ch == '(' || ch == ')' || ch == '-' || ch == '+') {
			special_char = true;
		}

	}

	return upper_case && lower_case && digit && special_char;
}


int main() {

	Customer c[3];
	std::string username, password;

	for (int i = 0; i < 3; i++) {
		std::cout << "\n\n\n\n\n\n";
		std::cout << std::setw(82) << "Dear Customer,Welcome To Beauty Parlor Management System!\n" << std::endl;

		//For signing up enter username and password
		std::cout << std::setw(50) << "Please Signup first." << std::endl;
		std::cout << std::setw(45) << "Enter username:";
		std::cin >> username;



		do {
			std::cout << "Before entering a password you should know that a strong password contains:\n";
			std::cout << "1.at least one lowercase English character.\n";
			std::cout << "2.at least one uppercase English character.\n";
			std::cout << "3.at least one special character.\n";
			std::cout << "4.at least one digit.\n";
			std::cout << "5.length is at least 8.\n";

			std::cout << std::setw(58) << "Now Enter a valid password:";
			std::cin >> password;
		} while (!valid_password(password));

		std::cout << std::setw(63) << "You have signed up successfully." << std::endl;

		std::cout << "\n\n";
		std::cout << std::setw(70) << "Please Enter the details for customer:" << i + 1 << std::endl;

		// calling input ftn to input the details of each customer
		c[i].input();

		std::cout << "Your details have entered successfully." << std::endl;

		//Enter "1" to logout your account
		int n;
		do {
			std::cout << "Please enter 1 to logout" << std::endl;
			std::cin >> n;
		} while (n != 1);

		std::cout << "Your account has logged out successfully." << std::endl;

	}

	std::ofstream outfile;
	outfile.open("management.bin", std::ios::out | std::ios::binary);
	if (!outfile) {
		std::cout << "File not opened";
		return 1;
	}

	//Writing record of each customer in binary file
	for (int i = 0; i < 3; i++) {
		c[i].writefile(outfile);
	}
	//Close the file
	outfile.close();

	//Menu 
	std::cout << "Please read this menu:" << std::endl;

	std::cout << "\n";
	std::cout << "Press 1 to add an item." << std::endl;
	std::cout << "Press 2 to update an item." << std::endl;
	std::cout << "Press 3 to delete an item." << std::endl;
	std::cout << "Press 4 to search an item." << std::endl;
	std::cout << "Press 5 to write in csv file." << std::endl;
	std::cout << "Press 6 to read from csv file." << std::endl;
	std::cout << "Press 7 if you want kind of help." << std::endl;
	std::cout << "Press 8 to exit." << std::endl;
	std::cout << "\n\n";

	int option, num_customer;
	do {

		do {
			std::cout << "Please Enter a valid option(1 to 8):" << std::endl;
			std::cin >> option;
		} while (option < 1 || option > 8);

		if (option == 1) {
			do {
				std::cout << "Please Enter valid customer number(i.e.0-2) in which you want to add item:" << std::endl;
				std::cin >> num_customer;
			} while (num_customer < 0 || num_customer>2);

			add_item(c[num_customer]);  // Calling add_item() ftn

			std::ofstream outfile;
			outfile.open("management.bin", std::ios::out | std::ios::binary);

			for (int i = 0; i < 3; i++) {
				c[i].writefile(outfile);
			}
			outfile.close();
		}

		else if (option == 2) {
			do {
				std::cout << "Please Enter valid customer number(i.e.0-2) in which you want to update item:" << std::endl;
				std::cin >> num_customer;
			} while (num_customer < 0 || num_customer>2);

			update_item(c[num_customer]);  // Calling update_item() ftn

			std::ofstream outfile;
			outfile.open("management.bin", std::ios::out | std::ios::binary);

			for (int i = 0; i < 3; i++) {
				c[i].writefile(outfile);
			}
			outfile.close();
		}

		else if (option == 3) {
			do {
				std::cout << "Please Enter valid customer number(i.e.0-2) in which you want to delete item:" << std::endl;
				std::cin >> num_customer;
			} while (num_customer < 0 || num_customer>2);

			delete_item(c[num_customer]);    // // Calling delete_item() ftn

			std::ofstream outfile;
			outfile.open("management.bin", std::ios::out | std::ios::binary);

			for (int i = 0; i < 3; i++) {
				c[i].writefile(outfile);
			}
			outfile.close();

		}

		else if (option == 4) {
			do {
				std::cout << "Please Enter valid customer number(i.e.0-2) in which you want to search item:" << std::endl;
				std::cin >> num_customer;
			} while (num_customer < 0 || num_customer>2);

			search_item(c[num_customer]);   // Calling search_item() ftn
		}

		else if (option == 5) {

			std::ofstream outfile;
			outfile.open("management.csv", std::ios::out);
			if (!outfile) {
				std::cout << "File not opened";
				return 1;
			}
			for (int i = 0; i < 3; i++) {
				c[i].write_csv(outfile);   // Calling write_csv() ftn
			}
			outfile.close();
		}

		else if (option == 6) {

			std::ifstream infile;
			infile.open("management.csv", std::ios::in);
			if (!infile) {
				std::cout << "File not opened";
				return 1;
			}
			for (int i = 0; i < 3; i++) {
				c[i].read_csv(infile);   // Calling read_csv() ftn
			}
			infile.close();
		}

		else if (option == 7) {
			help();  //calling help ftn

		}

		else if (option == 8) {
			return 0;  // exit

		}

		else {
			std::cout << "Invalid option" << std::endl;
		}

	} while (true);
}