#include <fstream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <vector>
#include "Object.h"
//#include "Supplier.h"
Object::Object(string Id, string DisplayName, string IdSupplier)
{
    this->Id = Id;
    this->DisplayName = DisplayName;
    this->IdSupplier = IdSupplier;
}
Object::~Object()
{

}
void Object::setId(string Id)
{
    this->Id = Id;
}
string Object::getId() const
{
    return this->Id;
}
void Object::setDisplayName(string DisplayName)
{
    this->DisplayName = DisplayName;
}
string Object::getDisplayName() const
{
    return this->DisplayName;
}
void Object::setIdSupplier(string IdSupplier)
{
    this->IdSupplier = IdSupplier;
}
string Object::getIdSupplier() const
{
    return this->IdSupplier;
}
//istream& operator>>(istream& i, Object& ob)
//{
    // ifstream input("InputObject.txt");
    // while(!input.eof())
    // {
    //     char str[100];
    //     const char Symbol[] = ", ";
    //     input >> str;
    //     char* p;
    //     p = strtok(str, Symbol);
    //     ob.setId(p);
    //     p = strtok(NULL, Symbol);
    //     ob.setDisplayName(p);
    //     p = strtok(NULL, Symbol);
    //     ob.setIdSuplier(p);
    //     cout << ob;
    // }
    // input.close();
    // return i;

ostream& operator<<(ostream& o, const Object& ob)
{
    o << left << setw(20) << ob.getId() << left << setw(20) << ob.getDisplayName() << left << setw(20) << ob.getIdSupplier() << endl;
    return o;
}
void Object::Show()
{
    Object ob;
    fstream input("InputObject.txt");
    if (!input.is_open()) {
        cout << "Cannot open file" << endl;
        return;
    }
    cout << left << setw(20) << "Id" << left << setw(20) << "DisplayName" <<
    left << setw(20) << "IdSuplier" << endl << endl;
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
        ob.setId(p);
        p = strtok(NULL, Symbol);
        if (p == nullptr) {
            continue; // Xử lý lỗi, ví dụ: bỏ qua dòng không hợp lệ
        }
        ob.setDisplayName(p);
        p = strtok(NULL, Symbol);
        if (p == nullptr) {
            continue; // Xử lý lỗi, ví dụ: bỏ qua dòng không hợp lệ
        }
        ob.setIdSupplier(p);
        cout << ob;
    }
    input.close();
}
void Object::Add()
{
string a, b, c;
    fstream input("InputObject.txt", ios::app);
    cout << "Nhap ID: ";
    cin >> a;
    cout << "Nhap DisplayName: ";
    cin >> b;
    cout << "IdSuplier:";
    cin >> c;
    //Object s1(a, b, c);
    input << a << "," << b << "," << c << endl;
    input.close();
}

void Object::Delete(string Id)
{
    fstream file("InputObject.txt", ios::in);
    if (!file.is_open()) {
        cout << "Cannot open file" << endl;
        return;
    }
    vector<Object> Remainlines;
    Object ob;
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string token;
        // Tokenize the line using ',' as delimiter
        vector<string> tokens;
        while (getline(iss, token, ',')) {
            tokens.push_back(token);
        }
        if (tokens.size() >= 3) {
            ob.setId(tokens[0]);
            ob.setDisplayName(tokens[1]);
            ob.setIdSupplier(tokens[2]);
            if (ob.Id != Id) {
                Remainlines.push_back(ob);
            }
        }
    }
    file.close();
    // Reopen the file in write mode to clear its content
    file.open("InputObject.txt", ios::out | ios::trunc);
    // Rewrite the remaining lines to the file
    for (const auto& obj : Remainlines) {
        file << obj.getId() << "," << obj.getDisplayName() << "," << obj.getIdSupplier() << endl;
    }
    file.close();
}
