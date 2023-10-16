#include <string>
#include <iostream>
#include <fstream>
using namespace std;

fstream bookFiles;

class book {
private:
	float price;
	int year;
	char author[20], title[30];
public:
	void getData();
	void print();
};

void book::getData() {
	bookFiles >> year >> price;
	bookFiles.getline(title, 30, '\n');
	bookFiles.getline(author, 20, '\n');
}

void book::print() {
	cout << "\nAuthor's name : " << author;
	cout << "\nBook title : " << title;
	cout << "\nBook price : " << price;
	cout << "\nBook published : " << year;
}

int main() {
	bookFiles.open("bookData.txt", ios::in);
	if (!bookFiles) {
		cerr << "ERROR!!!! Cannot open the file.";
		return 0;
	}

	book myBook[4];

	for (int j = 0; j < 4; j++) {
		myBook[j].getData();
	}
	for (int i = 0; i < 4; i++) {
		myBook[i].print();
	}

	bookFiles.close();
}
