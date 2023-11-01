#include <fstream>
#include <cstring>
#include <iomanip>
#include <vector>
#include "Customer.h"
Customer::Customer(string Id, string DisplayName, string Address, string Phone)
{
    this->Id = Id;
    this->DisplayName = DisplayName;
    this->Address = Address;
    if (Phone.size() == 10)
    {
        this->Phone = Phone;
    }
    else
    {
        cout << "This Phone number is invalid" << endl;
    }
}
Customer::~Customer()
{

}
void Customer::setId(string Id)
{
    this->Id = Id;
}
string Customer::getId() const
{
    return this->Id;
}
void Customer::setDisplayName(string DisplayName)
{
    this->DisplayName = DisplayName;
}
string Customer::getDisplayName() const
{
    return this->DisplayName;
}
void Customer::setAddress(string Address)
{
    this->Address = Address;
}
string Customer::getAddress() const
{
    return this->Address;
}
void Customer::setPhone(string Phone)
{
    if (Phone.size() == 10)
    {
        this->Phone = Phone;
    }
    else
        cout << "This Phone number is invalid" << endl;
}
string Customer::getPhone() const
{
    return this->Phone;
}
istream& operator>>(istream& i, Customer& c)
{
    // fstream input("InputCustomer.txt");
    // while(!input.eof())
    // {
    //     char str[100];
    //     const char Symbol[] = ", ";
    //     input >> str;
    //     char* p;
    //     p = strtok(str, Symbol);
    //     c.setId(p);
    //     p = strtok(NULL, Symbol);
    //     c.setDisplayName(p);
    //     p = strtok(NULL, Symbol);
    //     c.setAddress(p);
    //     p = strtok(NULL, Symbol);
    //     c.setPhone(p);
        //cout << c;
    // }
    // input.close();
    // return i;
}
ostream& operator<<(ostream& o, const Customer& c)
{
    o << left << setw(20) << c.getId() << left << setw(20) << c.getDisplayName() <<
    left << setw(20) << c.getAddress() << left << setw(20) << c.getPhone() << endl;
    return o;
}
void Customer::Show()
{
    Customer c;
    fstream input("InputCustomer.txt");
    if (!input.is_open()) {
        cout << "Cannot open file" << endl;
        return;
    }
    cout << left << setw(20) << "Id" << left << setw(20) << "DisplayName" <<
    left << setw(20) << "Address" << left << setw(20) << "Phone" << endl << endl;
    char str[100];
    const char Symbol[] = ", ";
    while(!input.eof())
    {
        input >> str;
        char* p;
        p = strtok(str, Symbol);
        if (p == nullptr) {
            continue; // Xử lý lỗi, ví dụ: bỏ qua dòng không hợp lệ
        }
        c.setId(p);
        p = strtok(NULL, Symbol);
        if (p == nullptr) {
            continue; // Xử lý lỗi, ví dụ: bỏ qua dòng không hợp lệ
        }
        c.setDisplayName(p);
        p = strtok(NULL, Symbol);
        if (p == nullptr) {
            continue; // Xử lý lỗi, ví dụ: bỏ qua dòng không hợp lệ
        }
        c.setAddress(p);
        p = strtok(NULL, Symbol);
        if (p == nullptr) {
            continue; // Xử lý lỗi, ví dụ: bỏ qua dòng không hợp lệ
        }
        c.setPhone(p);
        cout << c;
    }
    input.close();
}
void Customer::Add()
{
    string a, b, c, d;
    fstream input("InputCustomer.txt", ios::app);
    cout << "Nhap ID: ";
    cin >> a;
    cout << "Nhap DisplayName: ";
    cin >> b;
    cout << "Address: ";
    cin >> c;
    cout << "Phone: ";
    cin >> d;
    //Customer c1(a, b, c, d);
    input << a << "," << b << "," << c << "," << d << endl;
    input.close();
}

void Customer::Delete(string Id)
{
    fstream file("InputCustomer.txt", ios::in);
    if (!file.is_open()) {
        cout << "Cannot open file" << endl;
        return;
    }
    vector<Customer> Remainlines;
    Customer cus;
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string token;
        // Tokenize the line using ',' as delimiter
        vector<string> tokens;
        while (getline(iss, token, ',')) {
            tokens.push_back(token);
        }
        if (tokens.size() >= 4) {
            cus.setId(tokens[0]);
            cus.setDisplayName(tokens[1]);
            cus.setAddress(tokens[2]);
            cus.setPhone(tokens[3]);
            if (cus.Id != Id) {
                Remainlines.push_back(cus);
            }
        }
    }
    file.close();
    // Reopen the file in write mode to clear its content
    file.open("InputCustomer.txt", ios::out | ios::trunc);
    // Rewrite the remaining lines to the file
    for (const auto& c : Remainlines) {
        file << c.getId() << "," << c.getDisplayName() << "," << c.getAddress() << "," << c.getPhone() << endl;
    }
    file.close();
}
