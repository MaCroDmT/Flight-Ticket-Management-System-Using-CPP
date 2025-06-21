
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void signUp();
bool login(string& email);
void showHomePage(const string& email);
void bookTicket(const string& email);
void viewMyTrips(const string& email);
void makePayment(double amount);
void saveBookingToFile(const string& email, const string& ticketInfo);

int main() {
    int choice;
    string email;

    cout << "====== Flight Ticket Management System ======" << endl;
    cout << "1. Sign Up\n2. Login\nEnter choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        signUp();
    }

    if (login(email)) {
        showHomePage(email);
    } else {
        cout << "Login failed. Exiting...\n";
    }

    return 0;
}

void signUp() {
    string email, password;
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter password: ";
    cin >> password;

    ifstream infile("users.txt");
    string line;
    while (getline(infile, line)) {
        if (line.find(email) != string::npos) {
            cout << "Email already exists!\n";
            return;
        }
    }

    ofstream outfile("users.txt", ios::app);
    outfile << email << "," << password << endl;
    cout << "Sign up successful!\n";
}

bool login(string& email) {
    string password, line;
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter password: ";
    cin >> password;

    ifstream infile("users.txt");
    while (getline(infile, line)) {
        stringstream ss(line);
        string storedEmail, storedPassword;
        getline(ss, storedEmail, ',');
        getline(ss, storedPassword);

        if (email == storedEmail && password == storedPassword) {
            cout << "Login successful!\n";
            return true;
        }
    }

    return false;
}

void showHomePage(const string& email) {
    int choice;
    do {
        cout << "\n===== Home =====\n";
        cout << "1. Book a Ticket\n";
        cout << "2. My Trips\n";
        cout << "3. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bookTicket(email);
                break;
            case 2:
                viewMyTrips(email);
                break;
            case 3:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 3);
}

// Placeholder functions
void bookTicket(const string& email) {

    ifstream flightFile("flights.txt");
    vector<vector<string>> flights;
    string line;

    cout << "\n===== Available Flights =====\n";
    int index = 1;

    while (getline(flightFile, line)) {
        stringstream ss(line);
        string flightNo, from, to, date, time, seatClass, price;
        getline(ss, flightNo, ',');
        getline(ss, from, ',');
        getline(ss, to, ',');
        getline(ss, date, ',');
        getline(ss, time, ',');
        getline(ss, seatClass, ',');
        getline(ss, price);

        flights.push_back({flightNo, from, to, date, time, seatClass, price});
        cout << index++ << ". " << flightNo << " | From: " << from
             << " | To: " << to << " | Date: " << date << " | Time: " << time
             << " | Class: " << seatClass << " | Price: $" << price << endl;
    }

    if (flights.empty()) {
        cout << "No flights available.\n";
        return;
    }

    int choice;
    cout << "Enter the number of the flight you want to book: ";
    cin >> choice;

    if (choice < 1 || choice > flights.size()) {
        cout << "Invalid choice.\n";
        return;
    }

    vector<string> selectedFlight = flights[choice - 1];
    double amount = stod(selectedFlight[6]);

    makePayment(amount);


    string ticketInfo = selectedFlight[0] + "," + selectedFlight[1] + "," +
                        selectedFlight[2] + "," + selectedFlight[3] + "," +
                        selectedFlight[4] + "," + selectedFlight[5] + "," +
                        selectedFlight[6];

    saveBookingToFile(email, ticketInfo);

    cout << "Ticket booked successfully!\n";
}





void viewMyTrips(const string& email) {

    ifstream ticketFile("tickets.txt");
    string line;
    bool found = false;

    cout << "\n===== My Trips =====\n";

    while (getline(ticketFile, line)) {
        stringstream ss(line);
        string bookedEmail, flightNo, from, to, date, time, seatClass, price;

        getline(ss, bookedEmail, ',');
        if (bookedEmail != email) continue;

        getline(ss, flightNo, ',');
        getline(ss, from, ',');
        getline(ss, to, ',');
        getline(ss, date, ',');
        getline(ss, time, ',');
        getline(ss, seatClass, ',');
        getline(ss, price);

        found = true;
        cout << "Flight: " << flightNo
             << " | From: " << from
             << " | To: " << to
             << " | Date: " << date
             << " | Time: " << time
             << " | Class: " << seatClass
             << " | Price: $" << price << endl;
    }

    if (!found) {
        cout << "No trips found for your account.\n";
    }
}



void makePayment(double amount) {

    char choice;
    cout << "\nTotal amount to pay: $" << amount << endl;
    cout << "Do you want to proceed with the payment? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y') {
        cout << "Processing payment...\n";

        cout << "Payment successful!\n";
    } else {
        cout << "Payment cancelled.\n";

    }
}



void saveBookingToFile(const string& email, const string& ticketInfo) {
    ofstream ticketFile("tickets.txt", ios::app);
    ticketFile << email << "," << ticketInfo << endl;
}
