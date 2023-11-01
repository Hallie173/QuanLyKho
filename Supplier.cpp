#include <fstream>
#include <cstring>
#include <iomanip>
#include <vector>
#include "Supplier.h"
Supplier::Supplier(string Id, string DisplayName, string Address, string Phone)
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
Supplier::~Supplier()
{

}
void Supplier::setId(string Id)
{
    this->Id = Id;
}
string Supplier::getId() const
{
    return this->Id;
}
void Supplier::setDisplayName(string DisplayName)
{
    this->DisplayName = DisplayName;
}
string Supplier::getDisplayName() const
{
    return this->DisplayName;
}
void Supplier::setAddress(string Address)
{
    this->Address = Address;
}
string Supplier::getAddress() const
{
    return this->Address;
}
void Supplier::setPhone(string Phone)
{
    if (Phone.size() == 10)
    {
        this->Phone = Phone;
    }
    else
        cout << "This Phone number is invalid" << endl;
}
string Supplier::getPhone() const
{
    return this->Phone;
}
istream& operator>>(istream& i, Supplier& s)
{
    // ifstream input("InputSuplier.txt");
    // while(!input.eof())
    // {
    //     char str[100];
    //     const char Symbol[] = ", ";
    //     input >> str;
    //     char* p;
    //     p = strtok(str, Symbol);
    //     s.setId(p);
    //     p = strtok(NULL, Symbol);
    //     s.setDisplayName(p);
    //     p = strtok(NULL, Symbol);
    //     s.setAddress(p);
    //     p = strtok(NULL, Symbol);
    //     s.setPhone(p);
    //     cout << s;
    // }
    // input.close();
    // return i;
}
ostream& operator<<(ostream& o, const Supplier& s)
{
    o << left << setw(20) << s.getId() << left << setw(20) << s.getDisplayName() << left << setw(20) << s.getAddress() << left << setw(20) << s.getPhone() << endl;
    return o;
}
void Supplier::Show()
{
    Supplier s;
    fstream input("InputSupplier.txt");
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
        s.setId(p);
        p = strtok(NULL, Symbol);
        if (p == nullptr) {
            continue;
        }
        s.setDisplayName(p);
        p = strtok(NULL, Symbol);
        if (p == nullptr) {
            continue;
        }
        s.setAddress(p);
        p = strtok(NULL, Symbol);
        if (p == nullptr) {
            continue;
        }
        s.setPhone(p);
        cout << s;
    }
    input.close();
}
void Supplier::Add()
{
    string a, b, c, d;
    fstream input("InputSupplier.txt", ios::app);
    cout << "Nhap ID: ";
    cin >> a;
    cout << "Nhap DisplayName: ";
    cin >> b;
    cout << "Address: ";
    cin >> c;
    cout << "Phone: ";
    cin >> d;
    //Supplier s1(a, b, c, d);
    input << a << "," << b << "," << c << "," << d << endl;
    input.close();
}

void Supplier::Delete(string Id)
{
    fstream file("InputSupplier.txt", ios::in);
    if (!file.is_open()) {
        cout << "Cannot open file" << endl;
        return;
    }
    vector<Supplier> Remainlines;
    Supplier s;
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
            s.setId(tokens[0]);
            s.setDisplayName(tokens[1]);
            s.setAddress(tokens[2]);
            s.setPhone(tokens[3]);
            if (s.Id != Id) {
                Remainlines.push_back(s);
            }
        }
    }
    file.close();
    // Reopen the file in write mode to clear its content
    file.open("InputSupplier.txt", ios::out | ios::trunc);
    // Rewrite the remaining lines to the file
    for (const auto& sup : Remainlines) {
        file << sup.getId() << "," << sup.getDisplayName() << "," << sup.getAddress() << "," << sup.getPhone() << endl;
    }
    file.close();
}

