//Simon Chewaka
//start date: 10/15
//Program 3
//due date: 10/17

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

// class of inventory object
class Object {
public:
    string type, name;
    float quantity, price, total;
};

int main() {
    int ch;
    cout << "1. Output electronics supplies to screen" << endl;
    cout << "2. Output office supplies to screen" << endl;
    cout << "3. Output office and electronics to summary.txt" << endl;
    cout << "Enter your choice: ";                    // input of choice
    cin >> ch;
    ifstream fr("Office.txt");
    string line;
    vector<Object> input;                                     // vector to store the inventory objects
    while (getline(fr, line)) {                             // read a line from file
        Object obj;
        istringstream ss(line);                         // make a string stream
        string token;
        getline(ss, token, ' ');                        // get tokens from the string stream
        obj.type = token;                                       // and put them into the variables
        getline(ss, token, ' ');
        obj.quantity = stof(token);
        getline(ss, token, ' ');
        obj.name = token;
        getline(ss, token, ' ');
        obj.price = stof(token);
        obj.total = obj.price * obj.quantity;
        input.push_back(obj);
    }
    fr.close();
    if (ch == 1) {                                                  // if choice 1 is selected
        float tot = 0;
        for (auto obj : input) {                        // iterate through the input vector
            if (obj.type == "O")                    // continue the loop if object is of Office supply
                continue;
            // print the details
            cout << obj.type << " ";
            cout << right << setw(20) << obj.name << " ";
            cout << "\t" << left << setw(10) << "Quantity: " << obj.quantity << " ";
            cout << "\t" << left << setw(14) << "price/piece: $" << obj.price << " ";
            cout << "\t" << setw(8) << "Total: $" << obj.total << endl;
            tot += obj.total;
        }
        cout << "------------------------------------------------------------" << endl;
        cout << "Total price for Electronics in Inventory: $" << tot << endl;
        cout << "------------------------------------------------------------" << endl;
    }
    else if (ch == 2) {                                             // if choice 2 is selected
        float tot = 0;
        for (auto obj : input) {
            if (obj.type == "E")                    // continue the loop is object is of electronics
                continue;
            // print the details
            cout << obj.type << " ";
            cout << right << setw(20) << obj.name << " ";
            cout << "\t" << left << setw(10) << "Quantity: " << obj.quantity << " ";
            cout << "\t" << left << setw(14) << "price/piece: $" << obj.price << " ";
            cout << "\t" << setw(8) << "Total: $" << obj.total << endl;
            tot += obj.total;
        }
        cout << "------------------------------------------------------------" << endl;
        cout << "Total price for Office Supplies in Inventory: $" << tot << endl;
        cout << "------------------------------------------------------------" << endl;
    }
    else if (ch == 3) {
        ofstream fw("Summary.txt");                     // create a file writer object
        float tot = 0;
        // iterate through the vector and write into the file
        for (auto obj : input) {
            if (obj.type == "O")
                continue;
            fw << obj.type << " ";
            fw << right << setw(20) << obj.name << " ";
            fw << "\t" << left << setw(10) << "Quantity: " << obj.quantity << " ";
            fw << "\t" << left << setw(14) << "price/piece: $" << obj.price << " ";
            fw << "\t" << setw(8) << "Total: $" << obj.total << endl;
            tot += obj.total;
        }
        fw << "------------------------------------------------------------" << endl;
        fw << "Total price for Electronics in Inventory: $" << tot << endl;
        fw << "------------------------------------------------------------" << endl << endl;
        tot = 0;
        for (auto obj : input) {
            if (obj.type == "E")
                continue;
            fw << obj.type << " ";
            fw << right << setw(20) << obj.name << " ";
            fw << "\t" << left << setw(10) << "Quantity: " << obj.quantity << " ";
            fw << "\t" << left << setw(14) << "price/piece: $" << obj.price << " ";
            fw << "\t" << setw(8) << "Total: $" << obj.total << endl;
            tot += obj.total;
        }
        fw << "------------------------------------------------------------" << endl;
        fw << "Total price for Office Supplies in Inventory: $" << tot << endl;
        fw << "------------------------------------------------------------" << endl;
        fw.close();
    }
}
